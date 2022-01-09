#include <iostream>
#include <array>

class FIO {
private: std::string last_name,
	first_name,
	patronynic,
	full_name;

public: FIO();
public: ~FIO() {};

public: std::array<std::string, 4> GetInfo();
public: std::string GetFullName();


	 //function for demonstrate the disadvantages of surfase copying
public: void ChangeFullName(std::string);
};
