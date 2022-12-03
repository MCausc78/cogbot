#ifndef CXX_COGBOT_DATA_USER_HPP
#define CXX_COGBOT_DATA_USER_HPP 1

#include <dpp/dpp.h>

namespace cogbot::data {
	class user {
	private:
		dpp::snowflake id;
	public:
		user();
		user(cogbot::data::user &);
		user(dpp::snowflake);
		virtual ~user();
		long double get_balance();
		user& set_balance(long double);
		user& pay(long double, user &) noexcept(false);
		user& take(long double) noexcept(false);
		dpp::snowflake& get_id();
	};
}

#endif /* CXX_COGBOT_DATA_USER_HPP */