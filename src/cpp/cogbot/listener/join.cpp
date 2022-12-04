#include <algorithm>
#include "cogbot/listener/join.hpp"
#include "cogbot/util/snowflake.hpp"
#include "cogbot/main.hpp"

namespace cogbot::listener {
	void event_join_exec(const dpp::guild_member_add_t& event) {
		YAML::Node table = cogbot::config["bot"]["autorole"];
		std::string id = cogbot::util::snowflake::snowflake_to_string(event.adding_guild->id);
		if(!(table[id].IsDefined())) {
			return;
		}
		cogbot::bot->guild_member_add_role(
			event.adding_guild->id,
			event.added.user_id,
			dpp::snowflake(table[id].as<std::string>()));
	}
}