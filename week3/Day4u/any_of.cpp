#include "Functionalities.h"
#include <stdbool.h>


int main()
{
    EmployeeComtainer data1;
    Employee_ptrCon data2;
    EmployeeSmartContainer data3;

    CreateEmployee(data1);
    CreateEmployeeptr(data2);
    CreteSmartCon(data3);

    /*

    checkes if any one satisfys the condition*/
    bool flag = std::any_of(data1.begin(),data1.end(),[](const Employee& emp){
return emp.salary()>40000;
    });


    std::cout << std::boolalpha << flag<<'\n'; //<< std::noboolalpha for clear buffer

    //all of
    bool flag2 = std::all_of(data1.begin(), data1.end(), [](const Employee &emp)
                            { return emp.salary() > 40000; });

    std::cout<<flag2;
//
    bool flag3 = std::none_of(data1.begin(), data1.end(), [](const Employee &emp)
                            { return emp.salary() > 40000; });
                            std::cout<<flag3;

}