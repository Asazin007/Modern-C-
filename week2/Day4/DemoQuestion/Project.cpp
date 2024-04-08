#include "Project.h"
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "m_project_id: " << rhs.m_project_id
       << " doun: " << rhs.m_budget;
       if(rhs.m_project_type==ProjectType::BACKEND)
       os<< " m_project_type: " << "Backend";
       else
           os << " m_project_type: "
              << "Frontend";
    return os;
}

Project::Project(std::string id, double budget, ProjectType type)
:m_project_id(id),m_budget(budget),m_project_type(type)
{
}