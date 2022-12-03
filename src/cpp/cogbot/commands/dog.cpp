#include "cogbot/commands/dog.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include "cogbot/util/curl.hpp"

namespace cogbot::commands {
	void dog_exec(const dpp::slashcommand_t& event) {
		dpp::embed emb = dpp::embed().
			set_color(dpp::colors::red).
			set_title("Ошибка");
		CURL *ch;
		CURLcode res;
		ch = curl_easy_init();
		curl_easy_setopt(ch, CURLOPT_URL, "https://random.dog/woof.json");
		curl_easy_setopt(ch, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(ch, CURLOPT_TIMEOUT, 1L);
		curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, cogbot::util::curl::write_std_string);
		std::string js;
		curl_easy_setopt(ch, CURLOPT_WRITEDATA, &js);
		res = curl_easy_perform(ch);
		curl_easy_cleanup(ch);
		std::cout << fmt::format("dogjs=`{}`\n", js) << std::flush;
		nlohmann::json j = nlohmann::json::parse(js);
		if(res != CURLE_OK) {
			emb.set_description(fmt::format("Ошибка libcurl: {} (`{}`)",
				res,
				curl_easy_strerror(res)
			));
			event.reply(dpp::message(
				event.command.get_channel().id, emb
			).set_reference(event.command.msg.id));
			return;
		}
		emb.
			set_color(dpp::colors::white).
			set_image(j["url"]).
			set_title("Собачка");
		event.reply(
			dpp::message(
				event.command.get_channel().id, emb
			).set_reference(event.command.msg.id)
		);
	}
}
