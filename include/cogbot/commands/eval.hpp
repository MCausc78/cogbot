#ifndef CXX_COGBOT_COMMANDS_EVAL_HPP
#define CXX_COGBOT_COMMANDS_EVAL_HPP 1

#include <dpp/dpp.h>

/**
 *
 * @file eval.hpp
 * @brief Выполнить код
 *
 */

namespace cogbot::commands {
	/**
	 *
	 * @brief Команда /eval
	 * @param event объект события
	 *
	 */
	void eval_exec(const dpp::slashcommand_t &);
}

#endif /* CXX_COGBOT_COMMANDS_EVAL_HPP */