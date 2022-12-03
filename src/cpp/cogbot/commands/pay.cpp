#include "cogbot/commands/pay.hpp"
#include "cogbot/data/database.hpp"
#include "cogbot/data/user.hpp"
#include "cogbot/exceptions/sqluserpaybalanceexception.hpp"
#include "cogbot/exceptions/sqluserpaynegativeexception.hpp"
#include "cogbot/exceptions/sqluserpayzeroexception.hpp"
#include "cogbot/util/snowflake.hpp"
#include "cogbot/main.hpp"

#include <fmt/core.h>

namespace cogbot::commands {
	void pay_exec(const dpp::slashcommand_t &event) {
		std::string amounts = std::get<std::string>(event.get_parameter("count"));
		long double amount = 0.0L;
		dpp::embed emb;
		emb.set_color(dpp::colors::red);
		try {
			amount = std::stold(amounts);
		} catch(std::invalid_argument const& ex) {
			emb.
				set_title("Ошибка парсинга").
				set_description(
					fmt::format("Парсинг невозможен ({})", ex.what())
				);
			event.reply(dpp::message(
				event.command.get_channel().id, emb).set_reference(event.command.msg.id));
			return;
		} catch(std::out_of_range const& ex) {
			emb.
				set_title("Ошибка парсинга").
				set_description(
					fmt::format("Парсинг возможен, но число выходит за пределы диапазона ({})", ex.what())
				);
			event.reply(dpp::message(
				event.command.get_channel().id, emb).set_reference(event.command.msg.id));
			return;
		}
		auto du1 = cogbot::bot->user_get_sync(std::get<dpp::snowflake>(event.get_parameter("user")));
		dpp::user &du = dynamic_cast<dpp::user &>(du1);
		cogbot::data::user reciever(du.id);
		dpp::snowflake iu = event.command.get_issuing_user().id;
		cogbot::data::user sender(iu);
		emb.
			set_color(dpp::colors::red).
			set_title("❌ Ошибка");
		try {
			reciever.pay(amount, sender);
			emb.
				set_color(dpp::colors::green).
				set_title("✅ Успешно").
				add_field("Действие", "Передать деньги").
				add_field("Отправитель", fmt::format("<@{}>",
					cogbot::util::snowflake::snowflake_to_string(
						const_cast<dpp::snowflake &>(event.command.get_issuing_user().id)
					))
				).
				add_field("Получатель", fmt::format("<@{}>",
					cogbot::util::snowflake::snowflake_to_string(
						du.id
					))
				).
				add_field("Количество", std::to_string(amount));
			event.reply(dpp::message(
				event.command.get_channel().id, emb).set_reference(event.command.msg.id));
		} catch(exceptions::sqluserpaybalanceexception &ex) {
			emb.
				set_description("Недостаточно денег!");
			event.reply(dpp::message(
				event.command.get_channel().id, emb).set_reference(event.command.msg.id));
		} catch(exceptions::sqluserpayzeroexception &ex) {
			emb.
				set_description("Значение не может быть нулевым!");
			event.reply(dpp::message(
				event.command.get_channel().id, emb).set_reference(event.command.msg.id));
		} catch(exceptions::sqluserpaynegativeexception &ex) {
			emb.
				set_description("Значение не может быть отрицательным!");
			event.reply(dpp::message(
				event.command.get_channel().id, emb).set_reference(event.command.msg.id));
		}
	}
}
