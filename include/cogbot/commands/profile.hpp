#ifndef CXX_COGBOT_COMMANDS_PROFILE_HPP
#define CXX_COGBOT_COMMANDS_PROFILE_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file profile.hpp
 * @brief Профиль
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /profile
	 * @param event объект события
	 *
	 */
	void profile_exec(const dpp::slashcommand_t &);
}

#endif /* CXX_COGBOT_COMMANDS_PROFILE_HPP */