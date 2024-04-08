#ifndef PROJECT_H
#define PROJECT_H

#include "ProjectType.h"
#include <iostream>
class Project
{
private:
    std::string m_project_id;
    double m_budget;
    ProjectType m_project_type;

public:
    Project() = delete;
    Project(const Project &) = delete;            // disabled copy constructor
    Project(Project &&) = delete;                 // disabled move constructor brand new in C++11
    Project &operator=(const Project &) = delete; // disabled assignment operator
    Project &operator=(Project &&) = delete;      // disabled assignment move operator brand new in C++11
    ~Project() = default;
    Project(std::string id, double budget, ProjectType type);

    std::string projectId() const { return m_project_id; }
    void setProjectId(const std::string &project_id) { m_project_id = project_id; }

    ProjectType projectType() const { return m_project_type; }
    void setProjectType(const ProjectType &project_type) { m_project_type = project_type; }

    double m_getDoun() const { return m_budget; }
    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
