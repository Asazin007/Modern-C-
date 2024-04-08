#include "Functionalities.h"

int main(){
    EmployeeComtainer data1;
    Employee_ptrCon data2;
    EmployeeSmartContainer data3;

    CreateEmployee(data1);
    CreateEmployeeptr(data2);
    CreteSmartCon(data3);

    //----------------------------------count-if
    /* 
    takes predicate(lamda for true or false)
    takes iterator, begin , end
    returns size
     */
    int count = std::count_if(data1.begin(),
                              data1.end(),
                              [](const Employee &e)
                              {
                                  return e.salary() > 40000.0f;
                              });
    std::cout<<"count of data1 : "<<count;
    std::cout<<std::count_if(data2.begin(),
                              data2.end(),
                              [](const Employee* &e)
                              {
                                  return e->salary() > 40000.0f;
                              })<<'\n';
    std::cout<< std::count_if(data3.begin(),
                  data3.end(),
                  [](const EmployeeSmartptr &e)
                  {
                      return e->salary() > 40000.0f;
                          
                  })<<'\n';


}