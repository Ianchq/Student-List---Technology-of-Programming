#include "Student.h"

Student::Student() : groupNumber(0) {}

Student::Student(const std::string &name, int group) : fullName(name), groupNumber(group) {}

Student::Student(string str)
{
    string name;
    int group;
    string subject;
    int grade;
    istringstream iss(str);
    iss >> name >> group >> subject >> grade;
    this->fullName = name;
    this->groupNumber = group;
    this->subject = subject;
    this->grade = grade;
}

Student::~Student() {}

std::string Student::getFullName() const
{
    return fullName;
}

int Student::getGroupNumber() const
{
    return groupNumber;
}

// std::vector<std::pair<std::string, int>> Student::getGrades() const
// {
//     return grades;
// }

void Student::setFullName(const std::string &name)
{
    fullName = name;
}

void Student::setGroupNumber(int group)
{
    groupNumber = group;
}

void Student::setSubject(int subject)
{
    this->subject = subject;
}

void Student::setGrade(int grade)
{
    this->grade = grade;
}

// void Student::addGrade(const std::string &subject, int grade)
// {
//     grades.push_back(std::make_pair(subject, grade));
// }

// std::ostream &operator<<(std::ostream &os, const Student &student)
// {
//     os << "Name: " << student.fullName << "\nGroup: " << student.groupNumber << "\nGrades:\n";
//     for (const auto &grade : student.grades)
//     {
//         os << grade.first << ": " << grade.second << "\n";
//     }
//     return os;
// }

// std::istream &operator>>(std::istream &is, Student &student)
// {
//     std::cout << "Enter name: ";
//     std::getline(is, student.fullName);

//     std::cout << "Enter group number: ";
//     is >> student.groupNumber;

//     std::cout << "Введите оценки по каждому предмету"; //"end" to stop
//     while (true)
//     {
//         std::string subject;
//         int grade;

//         is >> subject;
//         if (subject == "end")
//             break;
//         is >> grade;

//         student.addGrade(subject, grade);
//     }
//     return is;
// }

// double Student::getAvarageGrade() const
// {
//     if (grades.empty())
//         return 0.0;

//     int total = 0;
//     for (const auto &grade : grades)
//     {
//         total += grade.second;
//     }

//     return static_cast<double>(total) / grades.size();
// }

// bool compareStudents(const Student &student1, const Student &student2)
// {
//     return student1.getAvarageGrade() < student2.getAvarageGrade();
// }

void Student::setUnit()
{
    std::cout << "Name: ";
    std::cin >> this->fullName;
    std::cout << std::endl;
    std::cout << "Group: ";
    std::cin >> this->groupNumber;
    std::cout << std::endl;
    std::cout << "Subject: ";
    std::cin >> this->subject;
    std::cout << std::endl;
    std::cout << "Grade: ";
    std::cin >> this->grade;
    std::cout << std::endl;
}

void Student::PrintDetails(ostream &os) const
{
    os << "Student: ";
    os << this->fullName << " ";
    os << this->groupNumber << " ";
    os << this->subject << " ";
    os << this->grade << endl;
}

void Student::ReadDetails(istream &is)
{
    is >> fullName >> groupNumber >> subject >> grade;
}
