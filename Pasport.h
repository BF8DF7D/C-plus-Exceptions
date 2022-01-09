#include <iostream>
#include <array>

class Pasport {
private: int series,
	number;

public:	Pasport();
public:	~Pasport() {};

public: void SetFormat();
public: bool SetBool();
public: void PrintInfo();

public: std::array<int, 2> GetInfo();
};