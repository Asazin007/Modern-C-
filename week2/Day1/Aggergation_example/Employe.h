#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "Project.h"
#include <functional>
#include <ostream>
class Employee{
private:
    std::string m_emp_id;
    std::string m_employee_name;
    float m_employee_salary;
    std::reference_wrapper<Project> m_employee_project;

public: 
    Employee() = delete;
    Employee(const Employee &) = delete; // disabled copy constructor
    Employee(Employee &&) = delete; // disabled move constructor brand new in C++11
    Employee &operator=(const Employee &) = delete; // disabled assignment operator
    Employee &operator=(Employee &&) = delete;	  // disabled assignment move operator brand new in C++11
    Employee(std::string eid, std::string ename, float esalary, std::reference_wrapper<Project> eproject);
    ~Employee() = default;

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    /* 
    1) Indentation , Naming convection and appropriate use of comments 
    2) Multiple files with separate header and implementation.
    3) All functonalities working with proper output , proper corner case check;
    4)Main side client code

    less relevant:
    1) Use of smart pointers
    2)custum exception
    3)

     */
  
};

#endif // EMPLOYE_H
