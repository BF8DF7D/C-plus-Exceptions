#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iomanip>
#include <sstream>
#include <string>

Date::Date() {
	bool False_Input_Value;
	do {
		std::cout << " Дата: ";
		
		std::string date;
		std::getline(std::cin, date);
		for (int dot_position = 0; dot_position != -1;) {
			dot_position = date.find('.');
			if (dot_position != -1)
				date.replace(dot_position, 1, " ");
		}
		std::stringstream date_with_space(date);
		date_with_space >> day >> mounth >> year;
		
		False_Input_Value = !date_with_space.eof() || SetBool();
		if (False_Input_Value) {
			if (!date_with_space.eof())
				while (std::cin.get() != '\n');
			std::cout << "\n <Дата введена некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Date::SetBool(){
	enum Limit_Value {
		Minimum_for_days_and_months = 0,
		Minimum_value_for_years = 999,
		Maximum_day = 31,
		Maximum_mounth = 12,
		Maximum_years = 9999
	};

	bool False_Input_Value = (day <= Minimum_for_days_and_months || day > Maximum_day)
		|| (mounth <= Minimum_for_days_and_months || mounth > Maximum_mounth)
		|| (year <= Minimum_value_for_years || year > Maximum_years);

	return False_Input_Value;
}

void Time::ChangeTime(int changing_values[], Date& date) {
	enum Limit_Value {
		Quantity_minutes_for_hour = 60,
		Quantity_hours_for_days = 24,
		Quantity_days_for_mounths = 31,
		Quantity_mounth_for_year = 12,
	};
	int input_hour = changing_values[0],
		input_minutes = changing_values[1];

	minutes += input_minutes;
	hour += minutes / Quantity_minutes_for_hour + input_hour;
	minutes %= Quantity_minutes_for_hour;

	date.day += hour / Quantity_hours_for_days;
	hour %= Quantity_hours_for_days;
	date.mounth += date.day / Quantity_days_for_mounths;
	date.mounth %= Quantity_days_for_mounths;
	date.year += date.mounth / Quantity_mounth_for_year;
}

void Date::PrintInfo() {
	std::cout << std::setfill('0') << std::setw(2) << day << ".";
	std::cout << std::setfill('0') << std::setw(2) << mounth << ".";
	std::cout << std::setw(4) << year;
	std::cout.fill(' ');
}

std::array<int, 3> Date::GetInfo() {
	std::array<int, 3> date = { day, mounth, year };
	return date;
}
