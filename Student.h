#ifndef STUDENT_H
#define STUDENT_H

#include "iostream"
#include "vector"
#include "string"
#include "Keeper.h"

class Student
{

private:
    std::string fullName;
    int groupNumber;
    std::vector<std::pair<std::string, int>> grades;
    std::string subject;
    int grade;

public:
    Student();
    Student(const std::string &name, int group);
    Student(string str);

    std::string getFullName() const;
    int getGroupNumber() const;
    std::vector<std::pair<std::string, int>> getGrades() const;

    void setFullName(const std::string &name);
    void setGroupNumber(int group);
    void addGrade(const std::string &subject, int grade);

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend std::istream &operator>>(std::istream &is, Student &student);

    double Student::getAvarageGrade() const;
    bool compareStudents(const Student &student1, const Student &student2);

    void setUnit();
    void PrintDetails(std::ostream &os) const;
    void ReadDetails(istream &is);
};

#endif