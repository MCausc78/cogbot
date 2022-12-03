#ifndef CXX_COGBOT_COMMANDS_CAT_HPP
#define CXX_COGBOT_COMMANDS_CAT_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file cat.hpp
 * @brief Посмотреть на кота/кошку
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /cat
	 * @param event объект события
	 *
	 */
	void cat_exec(const dpp::slashcommand_t&);
}

#endif /* CXX_COGBOT_COMMANDS_CAT_HPP */