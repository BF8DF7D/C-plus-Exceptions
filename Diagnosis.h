#include "Talon.h"
#include "Disease.h"

class Diagnosis {
private: Talon* talon;		
private: Disease* disease;

public: Diagnosis(Talon* talon, Disease* disease);
public: Diagnosis();
public: ~Diagnosis() {};

public: void PrintInfo();
public: bool Empty();

public: Talon GetTalon();
public: Disease GetDisease();
public: Disease* GetAddressDisease();
public: Disease& GetLinkDisease();
};