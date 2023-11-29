#pragma once
#include "Student.h"
#include "MyException.h"

class Menu
{
private:
    Keeper *kep;
    std::string filename;
    void startMenu();
    void menuAdd();
    void menuDelete();
    // void menuEdit();
public:
    Menu();
};