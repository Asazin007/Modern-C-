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

return the first instanse of max element */

  auto itr =std::max_element(data1.begin(),data1.end(),[](Employee &emp1,Employee &emp2){
return emp1.salary()<emp2.salary();
  });

  std::cout<<*itr;

}