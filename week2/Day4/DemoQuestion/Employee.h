#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Project.h"
#include <functional>
#include "EmployeeType.h"
#include <ostream>
using Project_ref = std::reference_wrapper<Project> ;
class Employee
{
private:
    std::string m_emp_id;
    double m_salary;
    EmployeeType m_type;
    Project_ref m_project; 
public: 
    Employee() = delete;
    Employee(const Employee &) = delete; // disabled copy constructor
    Employee(Employee &&) = delete; // disabled move constructor brand new in C++11
    Employee &operator=(const Employee &) = delete; // disabled assignment operator
    Employee &operator=(Employee &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Employee() = default;
    Employee(std::string id, double sal, EmployeeType type, Project_ref project);

    // Project_ref project() const { return m_project; }
    

    EmployeeType type() const { return m_type; }
    void setType(const EmployeeType &type) { m_type = type; }

    double salary() const { return m_salary; }
    void setSalary(double salary) { m_salary = salary; }

    std::string empId() const { return m_emp_id; }
    void setEmpId(const std::string &emp_id) { m_emp_id = emp_id; }

    Project_ref project() const { return m_project; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
