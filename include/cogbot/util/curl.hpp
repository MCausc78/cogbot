#ifndef CXX_COGBOT_UTIL_CURL_HPP
#define CXX_COGBOT_UTIL_CURL_HPP 1

#include <cstdlib>

/**
 *
 * @file curl.hpp
 * @brief Представляет доступ ко libcURL.
 *
 */
namespace cogbot::util::curl {
	/**
	 *
	 * Записывает определенное количество элементов в строку.
	 *
	 * @param content откуда
	 * @param size размер каждого элемента
	 * @param n количество элементов
	 * @param target куда
	 *
	 */
	extern size_t write_std_string(void *, size_t, size_t, void *);
}

#endif /* CXX_COGBOT_UTIL_CURL_HPP */