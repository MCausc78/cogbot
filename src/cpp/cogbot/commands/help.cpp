#include "cogbot/commands/ping.hpp"
#include <cstdlib>

#include "cogbot/main.hpp"

namespace cogbot::commands {
	void help_exec(const dpp::slashcommand_t& event) {
		dpp::embed e = dpp::embed().
			set_color(dpp::colors::white).
			set_title("Помощь").
			set_description(
				"\n"
				BOT_PREFIX "help - Это\n"
				BOT_PREFIX "cat - Котик\n"
				BOT_PREFIX "dog - Собачка\n"
				"Приятного использования :3"
			).
			set_timestamp(std::time(NULL));
		event.reply(
			dpp::message(
				event.command.get_channel().id, e
			).set_reference(event.command.msg.id)
		);
	}
}
