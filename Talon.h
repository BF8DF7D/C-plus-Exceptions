#include "Doctor.h"
#include "Date.h"

class Talon{
private: Date Admission_Date;
private: Time Admission_Time;
private: int kabinet;
private: Doctor* medic;

public: Talon(Doctor*);
public: Talon();
public: Talon(Date, Time, int, Doctor&);
public: Talon(const Talon&);
public: ~Talon() {};

public: void PrintInfo();

public: friend Talon operator+(Talon&, std::string);
public:	friend Talon operator++(Talon&);
public: friend Talon operator++(Talon&, int);
public: Talon& operator=(const Talon&);

public: friend Talon* Doctor::CreateTalon();
public: friend void Doctor::ChangeTime(Talon*);

public: Date GetDate();
public: Time GetTime();
public: int GetKabinet();
public: Doctor GetDoctor();
	  

	  //functions for demonstarte disadvantages of surface copying
public: friend void Doctor::ChengeDoctor(std::string);
public: Doctor& GetLinkDoctor();
public: void ChengeKabinet(int);


};
