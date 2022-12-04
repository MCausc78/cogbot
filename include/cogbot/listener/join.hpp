#ifndef CXX_COGBOT_LISTENER_JOIN_HPP
#define CXX_COGBOT_LISTENER_JOIN_HPP 1

#include <dpp/dpp.h>

namespace cogbot::listener {
	void event_join_exec(const dpp::guild_member_add_t&);
}

#endif /* CXX_COGBOT_LISTENER_JOIN_HPP */