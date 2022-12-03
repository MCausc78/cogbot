#ifndef CXX_COGBOT_COMMAND_HPP
#define CXX_COGBOT_COMMAND_HPP 1

#include <dpp/dpp.h>
#include <functional>

namespace cogbot::commands {
	typedef struct {
		std::string description;
		std::function<void(const dpp::slashcommand_t &)> callback;
		std::vector<dpp::command_option> options;
	} command_t;
}

#endif /* CXX_COGBOT_COMMAND_HPP */