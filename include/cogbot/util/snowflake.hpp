#ifndef CXX_COGBOT_UTIL_SNOWFLAKE_HPP
#define CXX_COGBOT_UTIL_SNOWFLAKE_HPP 1

#include <dpp/dpp.h>
#include <string>

/**
 *
 * @file snowflake.hpp
 * @brief Представляет утилиты для работы с Discord API.
 *
 */
namespace cogbot::util::snowflake {
	/**
	 *
	 * Преобразывает `dpp::snowflake` в строку.
	 *
	 * @param id объект
	 *
	 */
	std::string snowflake_to_string(dpp::snowflake&);
}

#endif /* CXX_COGBOT_UTIL_SNOWFLAKE_HPP */