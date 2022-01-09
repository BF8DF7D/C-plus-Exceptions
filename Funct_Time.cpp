#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include <sstream>
#include "Time.h"

Time::Time() {
	bool False_Input_Value;
	do {
		std::cout << " Время: ";

		std::string time;
		std::getline(std::cin, time);
		for (int dot_position = 0; dot_position != -1;) {
			dot_position = time.find('.');
			if (dot_position != -1)
				time.replace(dot_position, 1, " ");
		}
		std::stringstream time_with_space(time);
		time_with_space >> hour >> minutes;

		False_Input_Value = !time_with_space.eof() || SetBool();

		if (False_Input_Value) {
			if (!time_with_space.eof())
				while (std::cin.get() != '\n');
			std::cout << "\n <Время введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Time::SetBool() {
	
	enum Limit_Value {
		Minimum_value_for_all = 0,
		Maximum_hour = 23,
		Maximum_minutes = 59
	};
	
	bool False_Input_Value = (hour < Minimum_value_for_all || hour > Maximum_hour)
		|| (minutes < Minimum_value_for_all || minutes > Maximum_minutes);

	return False_Input_Value;
}

void Time::PrintInfo() {
	std::cout << std::setfill('0') << std::setw(2) << hour << ".";
	std::cout << std::setfill('0') << std::setw(2) << minutes;
	std::cout.fill(' ');
}

std::array<int, 2> Time::GetInfo() {
	std::array<int, 2> time = { hour, minutes };
	return time;
}