#include "Functionalities.h"
#include <stdbool.h>
template <typename T, typename P>
bool Search(const T &data, const P &predicate)
{

    return std::all_of(
        data.begin(),
        data.end(),
        predicate);
}

int main()
{
    EmployeeComtainer data1;
    Employee_ptrCon data2;
    EmployeeSmartContainer data3;

    CreateEmployee(data1);
    CreateEmployeeptr(data2);
    CreteSmartCon(data3);

    /*

    return bools,
    check all */
    bool flag = Search<EmployeeComtainer, std::function<bool(const Employee &)>>(data1,
                                                                                 [](const Employee &emp)
                                                                                 {
                                                                                     return emp.salary() > 40000.0f;
                                                                                 });
int n =1;
    std::cout << std::boolalpha << flag; //<< std::noboolalpha for clear buffer
}