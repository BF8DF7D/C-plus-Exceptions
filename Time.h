#include <iostream>
#include <array>

class Date;

class Time {
private: int hour,
	minutes;

public: Time();
public: ~Time() {};

public: bool SetBool();
public: void PrintInfo();
public: void ChangeTime(int[], Date&);
public: std::array<int, 2> GetInfo();
	   
public: void ConstrTime(std::array<int, 2>);
};