#ifndef CXX_COGBOT_COMMANDS_HELP_HPP
#define CXX_COGBOT_COMMANDS_HELP_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file help.hpp
 * @brief Помощь по боту
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /help
	 * @param event объект события
	 *
	 */
	void help_exec(const dpp::slashcommand_t&);
}

#endif /* CXX_COGBOT_COMMANDS_HELP_HPP */