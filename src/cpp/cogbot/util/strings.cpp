#include "cogbot/util/strings.hpp"

#include <string>

namespace cogbot::util::strings {
	bool replace(std::string& target, const std::string& x, const std::string& y) {
		size_t start = target.find(x);
		if(start == std::string::npos)
			return false;
		target.replace(start, x.length(), y);
		return true;
	}
	void replace_all(std::string& target, const std::string& x, const std::string& y) {
		if(x.empty())
			return;
		size_t start = 0;
		while((start = target.find(x, start)) != std::string::npos) {
			target.replace(start, x.length(), y);
			start += y.length();
		}
	}
}
