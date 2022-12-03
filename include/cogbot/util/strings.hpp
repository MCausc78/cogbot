#ifndef CXX_COGBOT_UTIL_STRINGS_HPP
#define CXX_COGBOT_UTIL_STRINGS_HPP 1

#include <string>

/**
 *
 * @file strings.hpp
 * @brief Представляет доступ ко строкам.
 *
 */
namespace cogbot::util::strings {
	/**
	 *
	 * Заменяет подстроки 1 раз.
	 *
	 * @param target где
	 * @param from что
	 * @param to на что
	 *
	 */
	bool replace(std::string&, const std::string&, const std::string&);
	/**
	 *
	 * Заменяет все подстроки.
	 *
	 * @param target где
	 * @param from что
	 * @param to на что
	 *
	 */
	void replace_all(std::string&, const std::string&, const std::string&);
}

#endif /* CXX_COGBOT_UTIL_STRINGS_HPP */