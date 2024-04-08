#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    /* data */
    std::string m_name{""};
    std::string m_id{""};
    Employee *m_reportsto{nullptr};

public:
    Employee(/* args */) = default;
    Employee(const Employee &) = delete;
    Employee(const Employee &&) = delete;
    Employee operator=(const Employee &) = delete;
    Employee operator=(const Employee &&) = delete;
    Employee(std::string name, std::string id, Employee *reportto);

    virtual ~Employee()
    {
        if (m_reportsto)
            delete m_reportsto;
    }

    Employee *reportsto() const { return m_reportsto; }
    void setReportsto(Employee *reportsto) { m_reportsto = reportsto; }

    std::string id() const { return m_id; }

    std::string name() const { return m_name; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
