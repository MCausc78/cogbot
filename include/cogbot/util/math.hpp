#ifndef CXX_COGBOT_UTIL_MATH_HPP
#define CXX_COGBOT_UTIL_MATH_HPP 1

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
		unsigned long long factorial_asm(unsigned long long);
		/**
		 *
		 * Вычислить число Фибоначчи.
		 *
		 * @param n число
		 *
		 */
		unsigned long long fibonacci(unsigned long long);
	}
	/**
	 *
	 * Вычислить факториал числа, используя STL.
	 *
	 * @param n число
	 *
	 */
	long long factorial_stl(long long);
	/**
	 *
	 * Вычислить факториал числа, используя STL.
	 *
	 * @param n число
	 *
	 */
	unsigned long long factorial_stl(unsigned long long);
	/**
	 *
	 * Вычислить факториал числа, используя STL.
	 *
	 * @param n число
	 *
	 */
	long double factorial_stl(long double);

}

#endif /* CXX_COGBOT_UTIL_MATH_HPP */