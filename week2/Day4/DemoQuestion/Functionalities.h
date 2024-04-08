#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <memory>
#include <vector>
#include "Employee.h"

using Employee_ptr= std::shared_ptr<Employee>;
using Container= std::vector<Employee_ptr>;
using Project_ptr=std::shared_ptr<Project>;
using ProContainer= std::vector<Project_ptr>;


void CreateObj(Container & data, ProContainer& data2);

double MaxBudget(Container& data);


#endif // FUNCTIONALITIES_H
