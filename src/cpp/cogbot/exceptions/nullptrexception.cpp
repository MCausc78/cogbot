#include "cogbot/exceptions/nullptrexception.hpp"
#include <string>

namespace cogbot::exceptions {
	nullptrexception::nullptrexception() {
		this->reason = "";
	}
	nullptrexception::nullptrexception(std::string s) {
		this->reason = s;
	}
	nullptrexception::~nullptrexception() {
		
	}
	const char* nullptrexception::what() const throw() {
		return reason.c_str();
	}
}