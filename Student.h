#pragma once
#include "iostream"
#include "vector"
#include "string"
#include "Keeper.h"

struct SubjectGrade
{
    std::string subject;
    int grade;
};

class Student
{

private:
    std::string fullName;
    int groupNumber;
    // std::vector<std::pair<std::string, int>> grades;
    std::string subject;
    int grade;
    std::vector<SubjectGrade> grades;

public:
    Student();
    Student(const std::string &name, int group);
    Student(std::string str);
    Student(const Student &other);
    virtual ~Student()
    {
        std::cout << "Destructor Generalstd" << std::endl;
    };

    std::string getFullName() const;
    int getGroupNumber() const;
    const std::vector<SubjectGrade> &getGrades() const;
    double getAvarageGrade() const;
    // std::vector<std::pair<std::string, int>> getGrades() const;

    void setFullName(const std::string &name);
    void setGroupNumber(int group);
    // void addGrade(const std::string &subject, int grade);
    void setSubject(int subject);
    void setGrade(int grade);
    void addGrade(const std::string &subject, int grade);

    // double Student::getAvarageGrade() const;
    // bool compareStudents(const Student &student1, const Student &student2);

    void setUnit();
    void PrintDetails(std::ostream &os) const;
    void PrintDetailsPoor(std::ostream &os) const;
    void ReadDetails(std::istream &is);
};
