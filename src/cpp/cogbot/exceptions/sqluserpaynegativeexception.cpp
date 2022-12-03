#include "cogbot/exceptions/sqluserpaynegativeexception.hpp"
#include <string>

namespace cogbot::exceptions {
	sqluserpaynegativeexception::sqluserpaynegativeexception() {
		this->reason = "";
	}
	sqluserpaynegativeexception::sqluserpaynegativeexception(std::string s) {
		this->reason = s;
	}
	sqluserpaynegativeexception::~sqluserpaynegativeexception() {
		
	}
	const char* sqluserpaynegativeexception::what() const throw() {
		return reason.c_str();
	}
}