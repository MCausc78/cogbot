#ifndef CXX_COGBOT_COMMANDS_FACTORIAL_HPP
#define CXX_COGBOT_COMMANDS_FACTORIAL_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file factorial.hpp
 * @brief Вычислить факториал
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /factorial
	 * @param event объект события
	 *
	 */
	void factorial_exec(const dpp::slashcommand_t&);
}

#endif /* CXX_COGBOT_COMMANDS_FACTORIAL_HPP */