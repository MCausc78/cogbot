#include "cogbot/commands/factorial.hpp"
#include "cogbot/util/math.hpp"

#include <cstdint>
#include <cstdlib>
#include <fmt/core.h>
#include <string>

namespace cogbot::commands {
	void factorial_exec(const dpp::slashcommand_t& event) {
		std::string ns = std::get<std::string>(event.get_parameter("n"));
		long double n = 0.0L;
		dpp::embed e;
		e.set_color(dpp::colors::red);
		try {
			n = std::stold(ns);
		} catch(std::invalid_argument const& ex) {
			e.
				set_title("Ошибка парсинга").
				set_description(
					fmt::format("Парсинг невозможен ({})", ex.what())
				);
			event.reply(
				dpp::message(
					event.command.get_channel().id, e
				).set_reference(event.command.msg.id)
			);
			return;
		} catch(std::out_of_range const& ex) {
			e.
				set_title("Ошибка парсинга").
				set_description(
					fmt::format("Парсинг возможен, но число выходит за пределы диапазона ({})", ex.what())
				);
			event.reply(
				dpp::message(
					event.command.get_channel().id, e
				).set_reference(event.command.msg.id)
			);
			return;
		}
		if(n < 0 || n > 170) {
			e.
				set_title("Ошибка").
				set_description(
					"Выход за пределы диапазона! Доступные значения: от 0 до 170."
				);
			event.reply(
				dpp::message(
					event.command.get_channel().id, e
				).set_reference(event.command.msg.id)
			);
		} else {
			e.
				set_color(dpp::colors::green).
				set_title("Факториал был вычислен!").
				set_description(
					fmt::format("{}! = {}\n", n, cogbot::util::math::factorial_stl(n))
				);
			event.reply(
				dpp::message(
					event.command.get_channel().id, e
				).set_reference(event.command.msg.id)
			);
		}
	}
}
