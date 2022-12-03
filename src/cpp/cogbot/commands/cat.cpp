#include "cogbot/commands/cat.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include "cogbot/util/curl.hpp"
#include "cogbot/util/strings.hpp"

namespace cogbot::commands {
	void cat_exec(const dpp::slashcommand_t& event) {
		dpp::embed emb = dpp::embed().
			set_color(dpp::colors::red).
			set_title("Ошибка");
		CURL *ch;
		CURLcode res;
		ch = curl_easy_init();
		curl_easy_setopt(ch, CURLOPT_URL, "https://aws.random.cat/meow");
		curl_easy_setopt(ch, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(ch, CURLOPT_TIMEOUT, 1L);
		curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, cogbot::util::curl::write_std_string);
		std::string js;
		curl_easy_setopt(ch, CURLOPT_WRITEDATA, &js);
		long response_code = 0L;
		curl_easy_getinfo(ch, CURLINFO_RESPONSE_CODE, &response_code);
		res = curl_easy_perform(ch);
		curl_easy_cleanup(ch);
		std::cout << fmt::format("catjs=`{}`,res={}\n", js, res) << std::flush;
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
		if(response_code != 200) {
			emb.set_description(fmt::format("Ошибка! Рейт-лимит сервиса, пожалуйста подождите. ({})",
				response_code
			));
			event.reply(dpp::message(
				event.command.get_channel().id, emb
			).set_reference(event.command.msg.id));
			return;
		}
		nlohmann::json j = nlohmann::json::parse(js);
		std::string img = j["file"].get<std::string>();
		cogbot::util::strings::replace_all(img, "\\/", "/");
		emb.
			set_color(dpp::colors::white).
			set_image(img).
			set_title("Котик");
		event.reply(
			dpp::message(
				event.command.get_channel().id, emb
			).set_reference(event.command.msg.id)
		);
	}
}
