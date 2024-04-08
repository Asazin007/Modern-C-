#include "Employe.h"

Employee::Employee(std::string eid, std::string ename, float esalary, std::reference_wrapper<Project> eproject)
    : m_emp_id(eid), m_employee_name{ename}, m_employee_salary{esalary}, m_employee_project{eproject}
{
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "m_emp_id: " << rhs.m_emp_id
       << " m_employee_name: " << rhs.m_employee_name
       << " m_employee_salary: " << rhs.m_employee_salary
       << " m_employee_project: " << rhs.m_employee_project.get();
    return os;
}
