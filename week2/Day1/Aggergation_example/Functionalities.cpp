#include "Functionalities.h"

void CreateObject(Employee **employees, Project **project)
{
    project[0]=new Project("Pr101", 66700.0f,11);
    employees[0]= new Employee("emp101", "Harshit", 56000.0f,*project[0]);

    project[1] = new Project("Pr102", 86720.0f, 13);
    employees[1] = new Employee("emp102", "Gourav Kalyan", 56345.0f, *project[1]);
}