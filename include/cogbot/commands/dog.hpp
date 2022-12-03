#ifndef CXX_COGBOT_COMMANDS_DOG_HPP
#define CXX_COGBOT_COMMANDS_DOG_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file dog.hpp
 * @brief Посмотреть на собаку
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /dog
	 * @param event объект события
	 *
	 */
	void dog_exec(const dpp::slashcommand_t&);
}

#endif /* CXX_COGBOT_COMMANDS_DOG_HPP */