#include "Diagnosis.h"
#include <iostream>
#include <iomanip>



Diagnosis::Diagnosis(Talon* talon, Disease* disease) {
	this->talon = talon;
	this->disease = disease;
}

Diagnosis::Diagnosis() {
	talon = nullptr;
	disease = nullptr;
}

void Diagnosis::PrintInfo() {
	Date date = talon->GetDate();
	Time time = talon->GetTime();
	std::string name = talon->GetDoctor().GetFIO().GetFullName();

	std::cout << " Доктор: " << name << std::endl;
	std::cout << " Дата приёма: ";
	date.PrintInfo();
	std::cout << std::endl;
	std::cout << " Время приёма: ";
	time.PrintInfo();
	std::cout << std::endl;
	std::cout << " Номер кабинета: ";
	std::cout << std::setfill('0') << std::setw(3) << this->GetTalon().GetKabinet() << std::endl;
	std::cout.fill(' ');
	this->GetDisease().PrintInfo();
}

bool Diagnosis::Empty() {
	bool Empty_Diagnosis = true;
	if (talon || disease)
		Empty_Diagnosis = false;
	return Empty_Diagnosis;
}

Talon Diagnosis::GetTalon() {
	return *talon;
}

Disease Diagnosis::GetDisease() {
	return *disease;
}

Disease* Diagnosis::GetAddressDisease() {
	return disease;
}

Disease& Diagnosis::GetLinkDisease() {
	return *disease;
}
