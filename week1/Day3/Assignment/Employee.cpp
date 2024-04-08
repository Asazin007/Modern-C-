#include "Employee.h"
            

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "m_name: " << rhs.m_name
       << " m_id: " << rhs.m_id
       << " m_reportsto: " << rhs.m_reportsto;
    return os;
}



Employee::Employee(std::string name, std::string id, Employee *reportto)
:m_name{name},m_id{id},m_reportsto{reportto}
{
}
