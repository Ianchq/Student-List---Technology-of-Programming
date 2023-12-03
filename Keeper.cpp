#include "Keeper.h"
#include "Student.h"
#include "MyException.h"

Keeper::~Keeper()
{
    Node *tmp;
    while (head != nullptr)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    cout << "Destructor Keeper" << endl;
    system("pause");
}

void Keeper::addUnit(Student *unit)
{
    if (head == nullptr)
    {
        head = new Node(unit);
        lastUnit = head;
    }
    else
    {
        lastUnit->next = new Node(unit);
        lastUnit = lastUnit->next;
    }
    count++;
}

void Keeper::deleteUnit(int pos)
{
    if (pos < 0 || pos >= (count))
    {
        throw MyException("Out of range");
    }
    Node *tmp;
    Node *pred_del;
    Node *posle_del;

    if (pos == 0)
    {
        tmp = head;
        head = head->next;
        delete tmp;
        count -= 1;
    }
    else if (pos == (count - 1))
    {
        pred_del = head;
        for (size_t i = 0; i < pos - 1; i++)
        {
            pred_del = pred_del->next;
        }
        tmp = pred_del->next;
        pred_del->next = nullptr;
        lastUnit = pred_del;
        delete tmp;
        count--;
    }
    else
    {
        pred_del = head;
        for (size_t i = 0; i < pos - 1; i++)
        {
            pred_del = pred_del->next;
        }
        tmp = pred_del->next;
        posle_del = tmp->next;
        delete tmp;
        pred_del->next = posle_del;
        count--;
    }
}

void Keeper::printToConsole()
{
    Node *tmp = head;
    int i = 0;
    while (tmp != nullptr)
    {
        cout << i++ << " - ";
        tmp->PtrGen->PrintDetails(std::cout);
        tmp = tmp->next;
    }
}

void Keeper::printToConsolePoor()
{
    bool flagGrade2 = false;
    bool printedMessage = false;

    Node *current = head;

    while (current != nullptr)
    {
        const Student *student = current->PtrGen;

        for (const auto &SubjectGrade : student->getGrades())
        {

            if (SubjectGrade.grade == 2)
            {
                student->PrintDetailsPoor(std::cout);
                flagGrade2 = true;
                break;
            }
        }

        current = current->next;
    }

    if (!flagGrade2 && !printedMessage)
    {
        std::cout << "No students with grade 2 found." << std::endl;
        printedMessage = true;
    }
}

void Keeper::loadToFile(string nameFile)
{
    ofstream outputFile(nameFile);
    Node *tmp = head;
    while (tmp != nullptr)
    {
        tmp->PtrGen->PrintDetails(outputFile);
        tmp = tmp->next;
    }
    outputFile.close();
};

void Keeper::loadFromFile(string nameFile)
{
    ifstream readFile(nameFile);
    if (!readFile.is_open())
    {
        throw MyException("File not found");
    }
    string word;
    string line;
    while (!readFile.eof())
    {
        if (readFile >> word)
        {
            getline(readFile, line);
            this->addUnit(new Student(line));
            count += 1;
        }
        else
        {
            break;
        }
    }
    readFile.close();
}

Node &Keeper::operator[](const int index)
{
    Node *tmp = head;
    if (index < 0 || index >= (count))
    {
        throw MyException("Out of range");
    }

    for (size_t i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return *tmp;
}

void Keeper::sortStudents()
{
    if (count <= 1)
        return;

    Student **studentsArray = new Student *[count];
    Node *current = head;
    int index = 0;

    while (current != nullptr)
    {
        studentsArray[index++] = current->PtrGen;
        current = current->next;
    }

    std::sort(studentsArray, studentsArray + count, [](const Student *a, const Student *b)
              { return a->getAvarageGrade() < b->getAvarageGrade(); });

    head = new Node(studentsArray[0]);
    current = head;

    for (int i = 1; i < count; ++i)
    {
        current->next = new Node(studentsArray[i]);
        current = current->next;
    }

    delete[] studentsArray;
}

void Keeper::printLinesWithTwoDigitNumbers()
{
    Node *tmp = head;
    // int i = 0;
    while (tmp != nullptr)
    {
        int groupNumber = tmp->PtrGen->getGroupNumber();

        if (groupNumber >= 10 && groupNumber <= 99)
        {
            // cout << i++ << " - ";
            tmp->PtrGen->PrintDetails(std::cout);
        }

        tmp = tmp->next;
    }
}
