#define _CRT_SECURE_NO_WARNINGS
#include "FIO.h"
#include <string>
#include <sstream>
#include <iomanip>

FIO::FIO() {
	bool False_Input_Value;
	do {
		std::cout << " ФИО: ";

		std::getline(std::cin, full_name);
		std::stringstream Name_elements_stream(full_name);
		Name_elements_stream >> last_name >> first_name >> patronynic;
		False_Input_Value = patronynic.empty() || !Name_elements_stream.eof();

		if (False_Input_Value) {
			patronynic = "";
			std::cout << "\n <ФИО введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

std::array<std::string, 4> FIO::GetInfo() {
	std::array<std::string, 4> fio = { last_name,first_name,patronynic,full_name };
	return fio;
}

std::string FIO::GetFullName() {
	return full_name;
}





void FIO::ChangeFullName(std::string change) {
	full_name = change;
}