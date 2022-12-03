#include "cogbot/exceptions/sqluserpaybalanceexception.hpp"
#include <string>

namespace cogbot::exceptions {
	sqluserpaybalanceexception::sqluserpaybalanceexception() {
		this->reason = "";
	}
	sqluserpaybalanceexception::sqluserpaybalanceexception(std::string s) {
		this->reason = s;
	}
	sqluserpaybalanceexception::~sqluserpaybalanceexception() {
		
	}
	const char* sqluserpaybalanceexception::what() const throw() {
		return reason.c_str();
	}
}