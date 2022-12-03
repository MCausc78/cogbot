#ifndef CXX_COGBOT_COMMANDS_ABOUT_HPP
#define CXX_COGBOT_COMMANDS_ABOUT_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file about.hpp
 * @brief Получить информацию об боте
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * Команда /about
	 * @param event объект события
	 *
	 */
	void about_exec(const dpp::slashcommand_t&);
}

#endif /* CXX_COGBOT_COMMANDS_ABOUT_HPP */