#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Employee.h"
#include <memory>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>


using Employee_ptrCon = std::vector<Employee *>;
using EmployeeSmartptr = std::shared_ptr<Employee>;
using EmployeeSmartContainer = std::vector<EmployeeSmartptr>;
using EmployeeComtainer = std::vector<Employee>;
using fntype = std::function<void(EmployeeComtainer &)>;
void CreateEmployee(EmployeeComtainer &data)
{
    data.push_back(Employee(
        "Harshit", 105678.0f, "Trainer", 10));

    data.push_back(Employee(
        "Asim", 45878.0f, "Trainee", 10));
    data.push_back(Employee(
        "Gourav", 55678.0f, "Trainee", 10));
    data.push_back(Employee(
        "Ayush", 48678.0f, "Trainer", 10));
}

void CreateEmployeeptr(Employee_ptrCon &data)
{

    data.push_back(new Employee(
        "Harshit", 105678.0f, "Trainer", 10));

    data.push_back(new Employee(
        "Asim", 45878.0f, "Trainer", 10));
    data.push_back(new Employee(
        "Gourav", 45678.0f, "Trainer", 10));
    data.push_back(new Employee(
        "Ayush", 48678.0f, "Trainer", 10));
}
void CreteSmartCon(EmployeeSmartContainer &data)
{

    data.push_back(std::make_shared<Employee>(
        "Harshit", 105678.0f, "Trainer", 10));

    data.push_back(std::make_shared<Employee>(
        "Asim", 45878.0f, "Trainer", 10));
    data.push_back(std::make_shared<Employee>(
        "Gourav", 45678.0f, "Trainer", 10));
    data.push_back(std::make_shared<Employee>(
        "Ayush", 48678.0f, "Trainer", 10));
}

#endif // FUNCTIONALITIES_H
