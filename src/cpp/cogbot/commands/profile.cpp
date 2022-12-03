#include "cogbot/commands/profile.hpp"
#include "cogbot/data/user.hpp"

namespace cogbot::commands {
    void profile_exec(const dpp::slashcommand_t& event) {
		dpp::snowflake iu = event.command.get_issuing_user().id;
		cogbot::data::user m(iu);
		dpp::embed emb;
		emb.
			set_color(dpp::colors::green).
			set_title("Профиль").
			add_field("Баланс", std::to_string(m.get_balance()));
		event.reply(dpp::message(
			event.command.get_channel().id, emb).set_reference(event.command.msg.id));
    }
}