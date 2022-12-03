#include "cogbot/util/snowflake.hpp"

#include <cstdint>
#include <fmt/core.h>
#include <string>
#include <dpp/dpp.h>

namespace cogbot::util::snowflake {
	std::string snowflake_to_string(dpp::snowflake& id) {
		return fmt::format("{:0>18}", (id.operator uint64_t()));
	}
}
