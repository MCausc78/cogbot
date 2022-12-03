#ifndef CXX_COGBOT_EXCEPTIONS_BASEEXCEPTION_HPP
#define CXX_COGBOT_EXCEPTIONS_BASEEXCEPTION_HPP 1

#include <exception>
#include <string>

/**
 *
 * @file baseexception.hpp
 * @brief Исключение.
 *
 */
namespace cogbot::exceptions {
	class baseexception : public std::exception {
	protected:
		/**
		 *
		 * @brief Причина исключения.
		 *
		 */
		std::string reason;
	public:
		/**
		 *
		 * @brief Конструктор исключения по умолчанию.
		 *
		 */
		baseexception();
		/**
		 *
		 * @brief Конструктор исключения с причиной.
		 *
		 * @param reason причина
		 *
		 */
		baseexception(std::string);
		/**
		 *
		 * @brief Деструктор исключения по умолчанию.
		 *
		 */
		virtual ~baseexception();
		/**
		 *
		 * Получить причину.
		 *
		 * @return причина
		 *
		 */
		virtual const char* what() const throw();
	};
}

#endif /* CXX_COGBOT_EXCEPTIONS_BASEEXCEPTION_HPP */