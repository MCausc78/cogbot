#include "cogbot/exceptions/baseexception.hpp"
#include <string>

namespace cogbot::exceptions {
	baseexception::baseexception() {
		this->reason = "";
	}
	baseexception::baseexception(std::string s) {
		this->reason = s;
	}
	baseexception::~baseexception() {
		
	}
	const char* baseexception::what() const throw() {
		return reason.c_str();
	}
}