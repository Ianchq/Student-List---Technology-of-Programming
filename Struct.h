#include "Student.h"
struct Node
{
    Student *PtrGen;
    Node *next;

    Node(Student *g) : PtrGen(g), next(nullptr) {}
    ~Node()
    {
        delete PtrGen;
        cout << "Destructor Node" << endl;

        system("pause");
    }
};