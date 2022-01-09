#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>

void InputFormatInt(int& kabinet) {
	bool False_Input_Value;
	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 0,
		Maximum_number = 999,
		Clean_input_stream = '\n'
	};

	do {
		std::cout << " Номер кабинета: ";

		False_Input_Value = scanf("%d", &kabinet) != Quantity_input_value
			|| (kabinet <= Minimum_value_for_number || kabinet > Maximum_number)
			|| std::cin.get() != Clean_input_stream;

		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <Номер кабинета введен некорректно>" << std::endl;
		}

	} while (False_Input_Value);

}

Talon::Talon(Doctor* medic) {	
	InputFormatInt(kabinet);
	this->medic = medic;
	std::cout << " <Ввод завершён>" << std::endl;
}

Talon::Talon() {
	InputFormatInt(kabinet);
	medic = new Doctor();
}

Talon::Talon(Date inp_date, Time inp_time, int inp_kab, Doctor& inp_medic)
	: Admission_Date { inp_date }, 
	Admission_Time { inp_time },
	kabinet{ inp_kab },
	medic{ &inp_medic } 
{
	assert(inp_kab > 0 || inp_kab <= 999);
}

Talon::Talon(const Talon& copy) 
	: Admission_Date{ copy.Admission_Date },
	Admission_Time{ copy.Admission_Time },
	kabinet{ copy.kabinet },
	medic{ new Doctor(*copy.medic) }
{
}

void Talon::PrintInfo() {
	std::string name = GetDoctor().GetFIO().GetFullName();
	std::cout << " | "; 
	std::cout << std::setfill(' ') << std::setw(45) << name;
	std::cout << " | ";
	Admission_Date.PrintInfo();
	std::cout << " | ";
	Admission_Time.PrintInfo();
	std::cout << " | ";
	std::cout << std::setfill('0') << std::setw(3) << GetKabinet() << " |";
	std::cout.fill(' ');
	std::cout << std::endl;
}


Talon operator+(Talon& talon, std::string time) {
	for (int dot_position = 0; dot_position != -1;) {
		dot_position = time.find('.');
		if (dot_position != -1)
			time.replace(dot_position, 1, " ");
	}
	Talon value = talon;
	std::stringstream stream(time);
	int minutes = 0,
		hours = 0;
	stream >> hours >> minutes;

	int changing_values[] = { hours, minutes };
	value.Admission_Time.ChangeTime(changing_values, value.Admission_Date);
	return value;
}

Talon operator++(Talon& talon) {
	talon.kabinet += 1;
	return talon;
}

Talon operator++(Talon& talon, int) {
	Talon OldValue = talon;
	talon.kabinet += 1;
	return OldValue;
}

Talon& Talon::operator=(const Talon& copy) {
	Admission_Date = copy.Admission_Date;
	Admission_Time = copy.Admission_Time;
	kabinet = copy.kabinet;
	medic = new Doctor(*copy.medic);
	return *this;
}

Talon* Doctor::CreateTalon() {
	Talon* AdmissionDay = new Talon(this);
	return AdmissionDay;
}

void Doctor::ChangeTime(Talon* talon) {
	talon->Admission_Date = Date();
}

Date Talon::GetDate() {
	return Admission_Date;
}

Time Talon::GetTime() {
	return Admission_Time;
}

int Talon::GetKabinet() {
	return kabinet;
}

Doctor Talon::GetDoctor() {
	return *medic;
}









void Talon::ChengeKabinet(int change) {
	kabinet = change;
}

Doctor& Talon::GetLinkDoctor() {
	return *medic;
}

void Doctor::ChengeDoctor(std::string change) {
	Fio.ChangeFullName(change);
}