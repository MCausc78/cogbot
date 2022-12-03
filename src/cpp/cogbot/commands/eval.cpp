#include "cogbot/commands/eval.hpp"

namespace cogbot::commands {
	void eval_exec(const dpp::slashcommand_t &event) {
		dpp::embed emb = dpp::embed().
			set_color(dpp::colors::red).
			set_title("Ошибка").
			set_description(
				"К сожалению, реализовать данную команду должным образом невозможно по техническим причинам.");
		event.reply(dpp::message(
			event.command.get_channel().id, emb).set_reference(event.command.msg.id));
	}	
}
