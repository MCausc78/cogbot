#ifndef CXX_COGBOT_MAIN_HPP
#define CXX_COGBOT_MAIN_HPP 1

#include "cogbot/command.hpp"
#include <dpp/dpp.h>
#include <functional>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <pqxx/pqxx>

#ifndef BOT_PREFIX
#define BOT_PREFIX "/"
#endif /* BOT_PREFIX */

namespace cogbot {
	extern dpp::cluster *bot;
	extern std::map<std::string, cogbot::commands::command_t> cmds;
	class application {
	private:
		int argc;
		char **argv;
	public:
		application();
		application(int *, char ***) noexcept(false);
		virtual ~application();
		int run();		
	};
	extern YAML::Node config;
	extern pqxx::connection* conn;
	extern pqxx::work* txn;
	extern void app_shutdown(int);
	extern "C" int main(int, char **);
}

#endif /* CXX_COGBOT_MAIN_HPP */