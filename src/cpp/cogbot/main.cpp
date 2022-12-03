#include <dpp/dpp.h>
#include <cstdlib>

#include "cogbot/main.hpp"

#include "cogbot/commands/ping.hpp"
#include "cogbot/commands/help.hpp"
#include "cogbot/commands/factorial.hpp"
#include "cogbot/commands/about.hpp"
#include "cogbot/commands/dog.hpp"
#include "cogbot/exceptions/nullptrexception.hpp"
#include "cogbot/commands/cat.hpp"
#include "cogbot/commands/profile.hpp"
#include "cogbot/commands/pay.hpp"
#include "cogbot/commands/eval.hpp"
#include "cogbot/data/database.hpp"

#include <fmt/core.h>
#include <stdexcept>


namespace cogbot {
	dpp::cluster *bot = nullptr;
	std::map<std::string, cogbot::commands::command_t> cmds {
		{
			"ping",
			{
				"Пинг-понг!", cogbot::commands::ping_exec,
				{ }
			}
		},
		{
			"help",
			{
				"Помощь по боту", cogbot::commands::help_exec,
				{ }
			}
		},
		{
			"factorial",
			{
				"(Математика) Вычислить факториал", cogbot::commands::factorial_exec,
				{
					{
						dpp::co_string,
						"n",
						"Факториал",
						true
					}
				}
			}
		},
		{
			"about",
			{
				"Получить информацию об боте", cogbot::commands::about_exec,
				{ }
			}
		},
		{
			"dog",
			{
				"Посмотреть на собачку", cogbot::commands::dog_exec,
				{ }
			}
		},
		{
			"cat",
			{
				"Посмотреть на кота/кошку", cogbot::commands::cat_exec,
				{ }
			}
		},
		{
			"profile",
			{
				"Информация об себе", cogbot::commands::profile_exec,
				{ }
			}
		},
		{
			"pay",
			{
				"Заплатить", cogbot::commands::pay_exec,
				{
					{
						dpp::co_user,
						"user",
						"кому",
						true
					},
					{
						dpp::co_string,
						"count",
						"сколько",
						true
					}
				}
			}
		},
		{
			"eval",
			{
				"Выполнить код", cogbot::commands::eval_exec,
				{
					{
						dpp::co_string,
						"code",
						"код",
						true
					}
				}
			}
		}
	};
	application *app = nullptr;
	YAML::Node config;
	pqxx::connection* conn = nullptr;
	pqxx::work* txn = nullptr;
	void app_shutdown(int sig) {
		std::cout << std::endl << "Stopping bot" << std::endl;
		if(bot != nullptr) {
			bot->shutdown();
			bot = nullptr;
		}
	}
}

cogbot::application::application() {
	this->argc = 1;
	this->argv = {};
}

cogbot::application::application(int *argc, char ***argv) noexcept(false) {
	if( argc == nullptr
	||	argv == nullptr
	||	argc == NULL
	||	argv == NULL) {
		throw cogbot::exceptions::nullptrexception("cogbot::exceptions::nullptrexception: argc or argv is nullptrs/NULLs");
		return;
	}
	this->argc = *argc;
	this->argv = *argv;
}


cogbot::application::~application() {
	cogbot::app_shutdown(SIGINT);
}

int cogbot::application::run() {
	std::cout << "running...\n" << std::flush;
	try {
		cogbot::config = YAML::LoadFile("config.yml");
	} catch(std::exception& ex) {
		fmt::print(stderr, "Error when loading config.yml: {}\n", ex.what());
		return 1;
	}	
	cogbot::data::database::GET_BALANCE = fmt::format("SELECT balance FROM {} WHERE id = $1",
		cogbot::config["database"]
		["tables"]
		["users"].as<std::string>());
	cogbot::data::database::SET_BALANCE = fmt::format("UPDATE {} SET balance = $1 WHERE id = $2",
		cogbot::config["database"]
		["tables"]
		["users"].as<std::string>());
	cogbot::data::database::INSERT_BALANCE = fmt::format("INSERT INTO {} VALUES ( $1, $2 )",
		cogbot::config["database"]
		["tables"]
		["users"].as<std::string>());
	pqxx::connection conn(fmt::format(
		"postgresql://{}:{}@{}:{}/{}",
		cogbot::config["database"]["username"].as<std::string>(),
		cogbot::config["database"]["password"].as<std::string>(),
		cogbot::config["database"]["ip"].as<std::string>(),
		cogbot::config["database"]["port"].as<std::string>(),
		cogbot::config["database"]["database"].as<std::string>()
	));
	pqxx::work txn(conn);
	
	cogbot::conn = &conn;
	cogbot::txn = &txn;
	
	// discord api
	dpp::cluster bot(config["token"].as<std::string>());
	bot.on_log(dpp::utility::cout_logger());
	cogbot::bot = &bot;
	std::cout << "Starting bot..." << std::endl;
	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		try {
			cogbot::cmds.at(event.command.get_command_name()).callback.operator()(event);
		} catch(std::out_of_range oor) {
			dpp::embed e = dpp::embed().
				set_color(dpp::colors::red).
				set_title("Ошибка").
				set_description(fmt::format(
					"{}",
					oor.what()
				));
			event.reply(dpp::message(
				event.command.get_channel().id, e
			).set_reference(event.command.msg.id));
		}
	});
	bot.on_ready([&bot](const dpp::ready_t& event) {
		std::cout << "Bot started" << std::endl;
		if(dpp::run_once<struct register_bot_commands>()) {
			for (auto const& [cmd, v] : cogbot::cmds) {
				fmt::print("Registering command '{}'...\n", cmd);
				std::cout.flush();
				dpp::slashcommand sc(cmd, v.description, bot.me.id);
				for (dpp::command_option const& option : v.options) { 
					sc.add_option(option);
				}
				bot.global_command_create(sc);
			}
		}
	});
	signal(SIGINT, cogbot::app_shutdown);
	bot.start(dpp::st_wait);
	return 0;	
}

int cogbot::main(int argc, char **argv) {
	cogbot::application a(&argc, &argv);
	return a.run();
}
