#include "cogbot/util/curl.hpp"

#include <string>

namespace cogbot::util::curl {
	size_t write_std_string(void *contents, size_t size, size_t nmemb, void *userp) {
		((std::string*)userp)->append(
			(char*)contents,
			size * nmemb
		);
		return size * nmemb;
	}
}
