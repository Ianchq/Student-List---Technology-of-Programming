#ifndef STUDENT_H
#define STUDENT_H

#include "iostream"
#include "vector"
#include "string"

class Student
{

private:
    std::string fullName;
    int groupNumber;
    std::vector<std::pair<std::string, int>> grades;

public:
    Student();
    Student(const std::string &name, int group);

    std::string getFullName() const;
    int getGroupNumber() const;
    std::vector<std::pair<std::string, int>> getGrades() const;

    void setFullName(const std::string &name);
    void setGroupNumber(int group);
    void addGrade(const std::string &subject, int grade);

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend std::istream &operator>>(std::istream &is, Student &student);
};

#endif