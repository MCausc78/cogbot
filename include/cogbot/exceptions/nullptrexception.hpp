#ifndef CXX_COGBOT_EXCEPTIONS_NULLPTREXCEPTION_HPP
#define CXX_COGBOT_EXCEPTIONS_NULLPTREXCEPTION_HPP 1

#include "cogbot/exceptions/baseexception.hpp"

/**
 *
 * @file nullptrexception.hpp
 * @brief Исключение об нулевом указателе.
 *
 */
namespace cogbot::exceptions {
	class nullptrexception : public baseexception {
	public:
		/**
		 *
		 * @brief Конструктор исключения по умолчанию.
		 *
		 */
		nullptrexception();
		/**
		 *
		 * @brief Конструктор исключения с причиной.
		 *
		 * @param reason причина
		 *
		 */
		nullptrexception(std::string);
		/**
		 *
		 * @brief Деструктор исключения по умолчанию.
		 *
		 */
		virtual ~nullptrexception();
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

#endif /* CXX_COGBOT_EXCEPTIONS_NULLPTREXCEPTION_HPP */