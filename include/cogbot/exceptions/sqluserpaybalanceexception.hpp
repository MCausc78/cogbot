#ifndef CXX_COGBOT_EXCEPTIONS_SQLUSERPAYBALANCEEXCEPTION_HPP
#define CXX_COGBOT_EXCEPTIONS_SQLUSERPAYBALANCEEXCEPTION_HPP 1

#include "cogbot/exceptions/sqluserpayexception.hpp"

/**
 *
 * @file sqluserpaybalanceexception.hpp
 * @brief Исключение об недостатке баланса.
 *
 */
namespace cogbot::exceptions {
	class sqluserpaybalanceexception : public sqluserpayexception {
	public:
		/**
		 *
		 * @brief Конструктор исключения по умолчанию.
		 *
		 */
		sqluserpaybalanceexception();
		/**
		 *
		 * @brief Конструктор исключения с причиной.
		 *
		 * @param reason причина
		 *
		 */
		sqluserpaybalanceexception(std::string);
		/**
		 *
		 * @brief Деструктор исключения по умолчанию.
		 *
		 */
		virtual ~sqluserpaybalanceexception();
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

#endif /* CXX_COGBOT_EXCEPTIONS_SQLUSERPAYBALANCEEXCEPTION_HPP */
