#include "cogbot/commands/ping.hpp"

namespace cogbot::commands {
	void ping_exec(const dpp::slashcommand_t& event) {
		event.reply("Понг!");
	}
}
