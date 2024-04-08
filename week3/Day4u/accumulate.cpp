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
    functional programming 
    -map : applying a logic on all the data members
    -filter : extracting items that satisfies a condition from the data collection
    -reduce : collection / summurizing in one item
    eg- 10 20 30 40
    sum = 100
     */

/* 
rule 1: default op is binary +

 */
    std::cout<< "Addition : " << std::accumulate(
        data1.begin(),
        data1.end(),
        0.0f,
        [](float answer_upto_current_point, const Employee emp)
        {
            return answer_upto_current_point + emp.salary();
        })<<'\n';
    EmployeeComtainer xx;
std::accumulate(
                     data1.begin(),
                     data1.end(),
                     0.0f,
                     [&](float answer_upto_current_point, const Employee emp)
                     {
                        xx.push_back(emp);
                        return answer_upto_current_point * emp.salary();
                    
                     });

std::cout << std::endl << xx.size();

    
}