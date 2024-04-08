#include "Project.h"

Project::Project(std::string project, float projectbudget, unsigned int teamsize):
m_projectbudget(projectbudget),m_projectid(project),m_teamsize(teamsize)
{   
}
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "m_projectid: " << rhs.m_projectid
       << " m_projectbudget: " << rhs.m_projectbudget
       << " m_teamsize: " << rhs.m_teamsize;
    return os;
}
