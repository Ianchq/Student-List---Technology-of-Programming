#include "Menu.h"
#include <string>
#include <iostream>
#include "Keeper.h"

using namespace std;

Menu::Menu()
{
    kep = new Keeper;
    startMenu();
    delete kep;
}

void Menu::startMenu()
{
    char choose;
    while (1)
    {
        system("cls");
        std::cout << "Select command\n";
        std::cout << "1 - Add Element\n";
        std::cout << "2 - Delete Element\n";
        std::cout << "3 - Display Poor Students\n";
        std::cout << "4 - Sort Students from Low to High\n";
        std::cout << "5 - Display\n";
        std::cout << "6 - Display Lines with 2 Digit Numbers\n";
        std::cout << "7 - Save to file\n";
        std::cout << "8 - Extract from file\n";
        std::cout << "0 - Exit\n";
        std::cin >> choose;
        switch (choose)
        {
        case '1':
            menuAdd();
            break;
        case '2':
            menuDelete();
            break;
        case '3':
            kep->printToConsolePoor();
            system("pause");
            break;

        case '4':
            kep->sortStudents();
            system("pause");
            break;

        case '5':
            kep->printToConsole();
            system("pause");
            break;

        case '6':
            kep->printLinesWithTwoDigitNumbers();
            system("pause");
            break;

        case '7':
            system("cls");
            cout << "Enter filename:" << endl;
            cin >> filename;
            system("cls");
            kep->loadToFile(filename);
            break;

        case '8':
            system("cls");
            cout << "Enter filename:" << endl;
            cin >> filename;
            system("cls");
            try
            {
                kep->loadFromFile(filename);
            }
            catch (const MyException &e)
            {
                std::cerr << e.what() << '\n';
                system("pause");
            }

            break;
        case '0':
            return void();
        default:
            std::cout << "Incorrect command. Try again." << std::endl;
            cin.clear();
            system("pause");
            break;
        }
    }
}

void Menu::menuAdd()
{
    char choose;
    Student *tmp;

    tmp = new Student();
    tmp->setUnit();
    kep->addUnit(tmp);
}

void Menu::menuDelete()
{
    system("cls");
    int pos;
    while (1)
    {
        std::cout << "Enter the raw:";
        std::cin >> pos;

        try
        {
            kep->deleteUnit(pos);
        }
        catch (const MyException &e)
        {
            std::cerr << e.what() << '\n';
            system("pause");
        }
        break;
    }
}
