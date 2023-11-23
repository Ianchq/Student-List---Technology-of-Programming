#include "Student.h"

Student::Student() : groupNumber(0) {}

Student::Student(const std::string &name, int group) : fullName(name), groupNumber(group) {}

std::string Student::getFullName() const
{
    return fullName;
}

int Student::getGroupNumber() const
{
    return groupNumber;
}

std::vector<std::pair<std::string, int>> Student::getGrades() const
{
    return grades;
}

void Student::setFullName(const std::string &name)
{
    fullName = name;
}

void Student::setGroupNumber(int group)
{
    groupNumber = group;
}

void Student::addGrade(const std::string &subject, int grade)
{
    grades.push_back(std::make_pair(subject, grade));
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << "Name: " << student.fullName << "\nGroup: " << student.groupNumber << "\nGrades:\n";
    for (const auto &grade : student.grades)
    {
        os << grade.first << ": " << grade.second << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Student &student)
{
    std::cout << "Enter name: ";
    std::getline(is, student.fullName);

    std::cout << "Enter group number: ";
    is >> student.groupNumber;

    std::cout << "Введите оценки по каждому предмету"; //"end" to stop
    while (true)
    {
        std::string subject;
        int grade;

        is >> subject;
        if (subject == "end")
            break;
        is >> grade;

        student.addGrade(subject, grade);
    }
    return is;
}
