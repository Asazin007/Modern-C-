#include "Project.h"

Project::Project(std::string name, double budget, std::string assign)
:m_name{name}, m_budget{budget}, m_assinfn_to{assign}
{
}
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "m_name: " << rhs.m_name
       << " m_budget: " << rhs.m_budget
       << " m_assinfn_to: " << rhs.m_assinfn_to;
    return os;
}
