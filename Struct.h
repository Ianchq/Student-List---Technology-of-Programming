#pragma once
#include "Student.h"

class Student;

struct Node
{
    Student *PtrGen;
    Node *next;

    Node(Student *g) : PtrGen(g), next(nullptr) {}
    ~Node()
    {
        delete PtrGen;
        std::cout << "Destructor Node" << std::endl;

        system("pause");
    }
};
