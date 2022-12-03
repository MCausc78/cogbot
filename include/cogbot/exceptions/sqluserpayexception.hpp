#ifndef CXX_COGBOT_EXCEPTIONS_SQLUSERPAYEXCEPTION_HPP
#define CXX_COGBOT_EXCEPTIONS_SQLUSERPAYEXCEPTION_HPP 1

#include "cogbot/exceptions/baseexception.hpp"

/**
 *
 * @file sqluserpayexception.hpp
 * @brief Исключение об ошибке оплаты.
 *
 */
namespace cogbot::exceptions {
	class sqluserpayexception : public baseexception {
	public:
		/**
		 *
		 * @brief Конструктор исключения по умолчанию.
		 *
		 */
		sqluserpayexception();
		/**
		 *
		 * @brief Конструктор исключения с причиной.
		 *
		 * @param reason причина
		 *
		 */
		sqluserpayexception(std::string);
		/**
		 *
		 * @brief Деструктор исключения по умолчанию.
		 *
		 */
		virtual ~sqluserpayexception();
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

#endif /* CXX_COGBOT_EXCEPTIONS_SQLUSERPAYEXCEPTION_HPP */