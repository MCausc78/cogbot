#ifndef CXX_COGBOT_COMMANDS_PING_HPP
#define CXX_COGBOT_COMMANDS_PING_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file ping.hpp
 * @brief Посмотреть на пинг
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /ping
	 * @param event объект события
	 *
	 */
	void ping_exec(const dpp::slashcommand_t &);
}

#endif /* CXX_COGBOT_COMMANDS_PING_HPP */