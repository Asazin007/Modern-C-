#ifndef TALENTS_H
#define TALENTS_H

#include <iostream>
#include "Grade.h"
#include "Employee.h"
class Talents : public Employee
{
private:
    /* data */
    // std::string m_name;
    // std::string m_employeeID;
    Grade m_grade;
public:
    Talents(/* args */) = delete;
    Talents(const Talents &) = delete;
    Talents(const Talents &&) = delete;
    Talents operator=(const Talents &) = delete;
    Talents operator=(const Talents &&) = delete;
    Talents(std::string name, std::string employeeID, Grade grade,Employee* reportsto);
    ~Talents(){};

   

    Grade grade() const { return m_grade; }
    void setGrade(const Grade &grade) { m_grade = grade; }

    std::string getGradeString() const;

    friend std::ostream &operator<<(std::ostream &os, const Talents &rhs);
};

#endif // TALENTS_H
