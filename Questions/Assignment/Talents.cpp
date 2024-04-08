#include "Talents.h"


Talents::Talents(std::string name, std::string employeeID, Grade grade,Employee* reportsto)
:Employee(name,employeeID,reportsto), m_grade(grade)
{}

std::string Talents::getGradeString() const

{
    std::string grade;
    switch (this->m_grade)
    {
    case Grade::A_plus:
        /* code */

        grade = "A+";
        break;

    case Grade::A:
        grade = "A";
        break;

    case Grade::B:
        grade = "B";
        break;

    case Grade::C:
        grade = "C";
        break;
    case Grade::D:
        grade = "D";
        break;

    default:
        std::cout << "Invalid Grade!!";
        break;
    }

    return grade;
}
std::ostream &operator<<(std::ostream &os, const Talents &rhs)
{
    os << "Name: " << rhs.name()<<std::endl
       << " Employee ID: " << rhs.id()<<std::endl
       << " Grade: " << rhs.getGradeString();

    return os;
}
