#ifndef CXX_COGBOT_EXCEPTIONS_SQLUSERPAYZEROEXCEPTION_HPP
#define CXX_COGBOT_EXCEPTIONS_SQLUSERPAYZEROEXCEPTION_HPP 1

#include "cogbot/exceptions/sqluserpayexception.hpp"

/**
 *
 * @file sqluserpayzeroexception.hpp
 * @brief Исключение об нулевом количестве.
 *
 */
namespace cogbot::exceptions {
	class sqluserpayzeroexception : public sqluserpayexception {
	public:
		/**
		 *
		 * @brief Конструктор исключения по умолчанию.
		 *
		 */
		sqluserpayzeroexception();
		/**
		 *
		 * @brief Конструктор исключения с причиной.
		 *
		 * @param reason причина
		 *
		 */
		sqluserpayzeroexception(std::string);
		/**
		 *
		 * @brief Деструктор исключения по умолчанию.
		 *
		 */
		virtual ~sqluserpayzeroexception();
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

#endif /* CXX_COGBOT_EXCEPTIONS_SQLUSERPAYZEROEXCEPTION_HPP */