#include "cogbot/data/user.hpp"
#include "cogbot/data/database.hpp"
#include "cogbot/main.hpp"
#include "cogbot/exceptions/sqluserpaybalanceexception.hpp"
#include "cogbot/exceptions/sqluserpaynegativeexception.hpp"
#include "cogbot/exceptions/sqluserpayzeroexception.hpp"
#include "cogbot/util/snowflake.hpp"

namespace cogbot::data {
	user::user() {
		
	}
	user::user(cogbot::data::user &u) {
		this->id = u.get_id();
	}
	user::user(dpp::snowflake id) {
		this->id = id;
	}
	user::~user() {
		
	}
	long double user::get_balance() {
		cogbot::conn->prepare(
			"cxx_get_balance",
			cogbot::data::database::GET_BALANCE);
		pqxx::result res = cogbot::txn->exec_prepared("cxx_get_balance",
			cogbot::util::snowflake::snowflake_to_string(this->id));
		if(res.empty()) {
			cogbot::conn->prepare(
				"cxx_insert_balance",
				cogbot::data::database::INSERT_BALANCE);
			pqxx::result res = cogbot::txn->exec_prepared("cxx_insert_balance",
				cogbot::util::snowflake::snowflake_to_string(this->id),
				0.0);
			cogbot::txn->commit();
			return 0.0;
		}
		cogbot::txn->commit();
		return res[0]["balance"].as<long double>();
	}
	user& user::set_balance(long double n) {
		(void)get_balance();
		cogbot::conn->prepare(
			"cxx_set_balance",
			cogbot::data::database::SET_BALANCE);
		cogbot::txn->exec_prepared("cxx_set_balance",
			n,
			cogbot::util::snowflake::snowflake_to_string(this->id));
		cogbot::txn->commit();
		return *this;
	}
	user& user::pay(long double n, user &sender) noexcept(false) {
		if(sender.get_balance() < n) {
			throw exceptions::sqluserpaybalanceexception("not enough money");
		} else if(n == 0.0) {
			throw exceptions::sqluserpayzeroexception("cannot take zero value");
		} else if(n < 0.0) {
			throw exceptions::sqluserpaynegativeexception("value cannot be negative");
		}
		sender.take(n);
		return set_balance(get_balance() + n);
	}
	user& user::take(long double n) noexcept(false) {
		if(n < 0.0) {
			throw exceptions::sqluserpaynegativeexception("value cannot be negative");
		} else if(n == 0.0) {
			throw exceptions::sqluserpayzeroexception("cannot take zero value");
		} else if(n > get_balance()) {
			return set_balance(0.0);
		}
		return set_balance(get_balance() - n);
	}
	dpp::snowflake& user::get_id() {
		return this->id;
	}
}