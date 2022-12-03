#ifndef CXX_COGBOT_EXCEPTIONS_SQLUSERPAYNEGATIVEEXCEPTION_HPP
#define CXX_COGBOT_EXCEPTIONS_SQLUSERPAYNEGATIVEEXCEPTION_HPP 1

#include "cogbot/exceptions/sqluserpayexception.hpp"

/**
 *
 * @file sqluserpaynegativeexception.hpp
 * @brief Исключение об отрицательном количестве.
 *
 */
namespace cogbot::exceptions {
	class sqluserpaynegativeexception : public sqluserpayexception {
	public:
		/**
		 *
		 * @brief Конструктор исключения по умолчанию.
		 *
		 */
		sqluserpaynegativeexception();
		/**
		 *
		 * @brief Конструктор исключения с причиной.
		 *
		 * @param reason причина
		 *
		 */
		sqluserpaynegativeexception(std::string);
		/**
		 *
		 * @brief Деструктор исключения по умолчанию.
		 *
		 */
		virtual ~sqluserpaynegativeexception();
		/**
		 *
		 * @brief Получить причину.
		 *
		 * @return причина
		 *
		 */
		virtual const char* what() const throw();
	};
}

#endif /* CXX_COGBOT_EXCEPTIONS_SQLUSERPAYNEGATIVEEXCEPTION_HPP */