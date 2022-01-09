#include "FIO.h"

class Talon;


class Doctor {

private: FIO Fio;
private: std::string dolgnost;

public: Doctor();
public: ~Doctor() {};

public: void PrintInfo();

public: Talon* CreateTalon();
public: void ChangeTime(Talon*);

public: FIO GetFIO();
public: std::string GetDolgnost();



	  //function for demonstrate disadvantages of surface coping
public: void ChengeDoctor(std::string);
};