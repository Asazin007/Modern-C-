#include<iostream>
class Employee{
private:
std::string m_name;
double m_salary;
std::string m_designation;
    
public: 
    Employee() = delete;
    Employee(const Employee &) = delete; // disabled copy constructor
    Employee(Employee &&) = delete; // disabled move constructor brand new in C++11
    Employee &operator=(const Employee &) = delete; // disabled assignment operator
    Employee &operator=(Employee &&) = delete;	  // disabled assignment move operator brand new in C++11
    Employee( std::string name, double sal, std::string desig)
    :m_name{name}, m_salary{sal}, m_designation{desig}{}
    ~Employee() = default;

    std::string name() const { return m_name; }

    double salary() const { return m_salary; }

    std::string designation() const { return m_designation; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary
           << " m_designation: " << rhs.m_designation;
        return os;
    }

    
};