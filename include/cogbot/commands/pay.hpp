#ifndef CXX_COGBOT_COMMANDS_PAY_HPP
#define CXX_COGBOT_COMMANDS_PAY_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file pay.hpp
 * @brief Заплатить
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /pay
	 * @param event объект события
	 *
	 */
	void pay_exec(const dpp::slashcommand_t &);
}

#endif /* CXX_COGBOT_COMMANDS_PAY_HPP */