#include "cogbot/exceptions/sqluserpayexception.hpp"
#include <string>

namespace cogbot::exceptions {
	sqluserpayexception::sqluserpayexception() {
		this->reason = "";
	}
	sqluserpayexception::sqluserpayexception(std::string s) {
		this->reason = s;
	}
	sqluserpayexception::~sqluserpayexception() {
		
	}
	const char* sqluserpayexception::what() const throw() {
		return reason.c_str();
	}
}