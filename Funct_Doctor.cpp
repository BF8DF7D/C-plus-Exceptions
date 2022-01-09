#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

Doctor::Doctor() {
	std::cout << " Должность: ";
	std::getline(std::cin, dolgnost);
	std::cout << " <Ввод завершён>" << std::endl;
}

FIO Doctor::GetFIO() {
	return Fio;
}

std::string Doctor::GetDolgnost() {
	return dolgnost;
}

void Doctor::PrintInfo() {
	std::string fio = GetFIO().GetFullName();
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(45) << fio;
	std::cout << " | ";
	std::cout << std::setw(20) << GetDolgnost() << " |" << std::endl;
}