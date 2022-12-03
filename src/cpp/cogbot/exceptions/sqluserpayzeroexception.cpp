#include "cogbot/exceptions/sqluserpayzeroexception.hpp"
#include <string>

namespace cogbot::exceptions {
	sqluserpayzeroexception::sqluserpayzeroexception() {
		this->reason = "";
	}
	sqluserpayzeroexception::sqluserpayzeroexception(std::string s) {
		this->reason = s;
	}
	sqluserpayzeroexception::~sqluserpayzeroexception() {
		
	}
	const char* sqluserpayzeroexception::what() const throw() {
		return reason.c_str();
	}
}