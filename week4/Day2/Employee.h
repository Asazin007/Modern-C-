#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
class Employee{
private:
    std::string m_name{""};
    float m_salary{0.0f};
    std::string m_designation{""};
    int m_expyrs{-1};
    
public: 
    Employee() = default;
    Employee(std::string name, float sal, std::string des, int exp):
    m_name{name}, m_salary{sal}, m_designation{des}, m_expyrs{exp}{}
    Employee(const Employee &) = default; // disabled copy constructor
    Employee(Employee &&) = default; // disabled move constructor brand new in C++11
    Employee &operator=(const Employee &) = default; // disabled assignment operator
    Employee &operator=(Employee &&) = default;	  // disabled assignment move operator brand new in C++11
    ~Employee() = default;

    std::string designation() const { return m_designation; }
    void setDesignation(const std::string &designation) { m_designation = designation; }

    std::string name() const { return m_name; }

    float salary() const { return m_salary; }

    

    int expyrs() const { return m_expyrs; }

    void setName(const std::string &name) { m_name = name; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "m_name: " << rhs.m_name
       << " m_salary: " << rhs.m_salary
       << " m_designation: " << rhs.m_designation
       << " m_expyrs: " << rhs.m_expyrs;
    return os;
}

#endif // EMPLOYEE_H
