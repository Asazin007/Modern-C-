#ifndef PROJECT_H
#define PROJECT_H

#include<iostream>
class Project{
private:
std::string m_projectid;
float m_projectbudget;
unsigned int m_teamsize;
public: 
    Project() = delete;
    Project(const Project &) = delete; // disabled copy constructor
    Project(Project &&) = delete; // disabled move constructor brand new in C++11
    Project &operator=(const Project &) = delete; // disabled assignment operator
    Project &operator=(Project &&) = delete;	  // disabled assignment move operator brand new in C++11
    Project(std::string project, float projectbudget, unsigned int teamsize);

    ~Project() = default;

    std::string projectid() const { return m_projectid; }
    void setProjectid(const std::string &projectid) { m_projectid = projectid; }

    float projectbudget() const { return m_projectbudget; }
    void setProjectbudget(float projectbudget) { m_projectbudget = projectbudget; }

    unsigned int teamsize() const { return m_teamsize; }
    void setTeamsize(unsigned int teamsize) { m_teamsize = teamsize; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
