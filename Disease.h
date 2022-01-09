#include <iostream>
#include <vector>

class Disease{
private: std::string Name_Disease;
private: std::vector<std::string> Disease_Symptoms;
private: static int number_of_deaths;

public: Disease();
public: ~Disease() {};

public: void SetDisease();
public: void PrintInfo();
public: static void ChengeDeaths(int);

public: std::string GetName();
public: std::vector<std::string> GetSymptoms();
public: int GetDeaths();
};