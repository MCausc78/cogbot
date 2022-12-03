#ifndef CXX_COGBOT_UTIL_MATH_HPP
#define CXX_COGBOT_UTIL_MATH_HPP 1

#include <cstdint>

/**
 *
 * @file math.hpp
 * @brief Представляет доступ ко математическим функциям.
 *
 */
namespace cogbot::util::math {
	extern "C" {
		/**
		 *
		 * Вычислить факториал числа.
		 *
		 * @param n число
		 *
		 */
		uint64_t factorial(uint64_t);
		/**
		 *
		 * Вычислить число Фибоначчи.
		 *
		 * @param n число
		 *
		 */
		uint64_t fibonacci(uint64_t);
	}
}

#endif /* CXX_COGBOT_UTIL_MATH_HPP */