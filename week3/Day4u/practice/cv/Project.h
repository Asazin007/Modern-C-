#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
class Project
{
private:
    std::string m_name;
    double m_budget;
    std::string m_assinfn_to;

public:
    Project() = delete;
    Project(const Project &) = delete;            // disabled copy constructor
    Project(Project &&) = delete;                 // disabled move constructor brand new in C++11
    Project &operator=(const Project &) = delete; // disabled assignment operator
    Project &operator=(Project &&) = delete;      // disabled assignment move operator brand new in C++11
    Project(std::string name, double budget, std::string assign);
    ~Project() = default;

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    double budget() const { return m_budget; }
    void setBudget(double budget) { m_budget = budget; }

    std::string assinfnTo() const { return m_assinfn_to; }
    void setAssinfnTo(const std::string &assinfn_to) { m_assinfn_to = assinfn_to; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
