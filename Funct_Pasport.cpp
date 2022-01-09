#define _CRT_SECURE_NO_WARNINGS
#include "Pasport.h"
#include <iomanip>
#include <string>
#include <sstream>

Pasport::Pasport(){
	bool False_Input_Value;
	do {
		std::cout << " Паспорт: ";
		False_Input_Value = SetBool();
		
		std::string pasport;
		std::getline(std::cin, pasport);
		for (int dot_position = 0; dot_position != -1;) {
			dot_position = pasport.find('.');
			if (dot_position != -1)
				pasport.replace(dot_position, 1, " ");
		}
		std::stringstream pasport_with_space(pasport);
		pasport_with_space >> series >> number;
		False_Input_Value = !pasport_with_space.eof() || SetBool();
		
		if (False_Input_Value) {
			if (!pasport_with_space.eof())
				while (std::cin.get() != '\n');
			std::cout << "\n <Паспортные данные введены некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Pasport::SetBool() {
	enum Limit_Value {
		Minimum_value_for_all = 0,
		Maximum_for_series = 9999,
		Maximum_for_number = 999999,
	};
	bool False_Input_Value = (series <= Minimum_value_for_all || series > Maximum_for_series)
		|| (number < Minimum_value_for_all || number > Maximum_for_number);

	return False_Input_Value;
}

void Pasport::PrintInfo() {
	std::cout << std::setfill('0') << std::setw(4) << series;
	std::cout << " ";
	std::cout << std::setfill('0') << std::setw(6) << number;
	std::cout.fill(' ');
}

std::array<int, 2> Pasport::GetInfo() {
	std::array<int, 2> pasport = { series,number };
	return pasport;
}