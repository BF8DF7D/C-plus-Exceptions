#include "Pacient.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << std::endl;

    Date x = Date();
    x.PrintInfo();
}
