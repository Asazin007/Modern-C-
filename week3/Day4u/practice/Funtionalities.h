#ifndef FUNTIONALITIES_H
#define FUNTIONALITIES_H

#include "Employee.h"
#include <functional>
#include <memory>
#include <vector>
#include <future>
#include <algorithm>
#include <thread>
#include <numeric>

extern std::mutex mt;

using Employee_ptr = std::shared_ptr<Employee>;
using EmployeeContainer = std::vector<Employee_ptr>;

using Fntype1= std::function<void (EmployeeContainer&)>;
using Fntype2 = std::function<bool (EmployeeContainer&)>;
using Fntype3 = std::function<double(EmployeeContainer&)>;
using Fntype4 = std::function<Employee_ptr(EmployeeContainer &, std::future<std::string> &)>;
using Fntype5 = std::function<void(EmployeeContainer &, std::future<std::string> &)>;

extern Fntype1 CreateObject;
extern Fntype2 IsallsalAbove40k;
extern Fntype3 MaxSalary;
extern Fntype4 FindDetails;
extern Fntype5 FindWithdesig;




#endif // FUNTIONALITIES_H
