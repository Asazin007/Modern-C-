#include "Employee.h"

Employee::Employee(std::string id, double sal, EmployeeType type, Project_ref project)
:m_emp_id{id},m_salary{sal},m_type{type},m_project{project}
{
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "m_emp_id: " << rhs.m_emp_id
       << " m_salary: " << rhs.m_salary;
       if(rhs.m_type==EmployeeType::FULLTIME)
       os<< " m_type: " << "FullTime";
       if (rhs.m_type == EmployeeType::PARTTIME)
           os << " m_type: "
              << "Parttime";
              else
                  os << " m_type: "
                     << "Intern";
       os<< " m_project: " << rhs.m_project.get();
    return os;
}
