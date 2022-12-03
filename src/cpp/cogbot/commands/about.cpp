#include "cogbot/commands/about.hpp"
#include <cstdlib>

#include <curl/curl.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

namespace cogbot::commands {
	void about_exec(const dpp::slashcommand_t& event) {
		auto jsonlib = nlohmann::json::meta();
		curl_version_info_data *curllib = curl_version_info(CURLVERSION_NOW);
		dpp::embed emb = dpp::embed().
			set_color(dpp::colors::white).
			set_title("Об боте...");
		emb.
			add_field("Компилятор этой команды", (
				#ifdef __clang__
				"clang v" __clang_version__
				#elif defined(__GNUC__)
				"gcc v" __GNUC__ "." __GNUC_MINOR__ "." __GNUC_PATCHLEVEL__
				" (" __VERSION__ ")"
				#else
				"Неизвестно"
				#endif
			)).
			add_field("Стандарт C++",
				fmt::format("C++{:0>2} ({})", __cplusplus / 100 % 100, __cplusplus)
			).
			add_field("Какие библиотеки использует Cogbot?", fmt::format((
				"[{}](https://github.com/brainboxdotcc/DPP)\n"
				"[fmt v{}.{}.{}](https://github.com/fmtlib/fmt)\n"
				"[{} v{}]({})\n"
				"[libcurl v{} на {}](https://curl.se)\n"
				"[yaml-cpp](https://github.com/jbeder/yaml-cpp)\n"
				"[libpqxx](https://github.com/jtv/libpqxx)"),
				dpp::utility::version(),
				FMT_VERSION / 10000,
				FMT_VERSION / 100 % 100,
				FMT_VERSION % 100,
				jsonlib["name"],
				jsonlib["version"]["string"],
				jsonlib["url"],
				curllib->version,
				curllib->host
			)).
			add_field("Команда была скомпилирована...",
				"В " __TIME__ ", дата: " __DATE__ "."
			);
		event.reply(
			dpp::message(
				event.command.get_channel().id, emb
			).set_reference(event.command.msg.id)
		);
	}
}
