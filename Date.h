#include <iostream>
#include <array>
#include "Time.h"

class Date {
private: int day, 
	mounth, 
	year;

public: Date();
public: ~Date() {};

public: bool SetBool();
public: void PrintInfo();
public: friend void Time::ChangeTime(int[], Date&);
public: std::array<int, 3> GetInfo();
};