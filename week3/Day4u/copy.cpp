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
   

   EmployeeComtainer result (data1.size());

   std::copy(
    data1.begin(),
    data1.end(),
    result.begin()
   ); //copy the element of data1 from starting to end in result begin


/* 
count if has problem we dont know how many instanses the cindition has 
 */
//    EmployeeComtainer result2(std::count_if(data1.begin(),
//                                            data1.end(),
//                                            [](Employee &emp)
//                                            {
//                                                return emp.designation() == "Trainee";
//                                            }));

int count = 0;
EmployeeComtainer result2 (data1.size());
   auto itr= std::copy_if(
       data1.begin(),
       data1.end(),
       result2.begin(),
       [&count](Employee &emp)
       {
            if(emp.designation() == "Trainee"){
                count++;
            }
           return emp.designation() == "Trainee";
       });

   //it should have 2 size but have 4

        /*
        m_name: Asim m_salary: 45878 m_designation: Trainee m_expyrs: 10
m_name: Gourav m_salary: 45678 m_designation: Trainee m_expyrs: 10
m_name:  m_salary: 0 m_designation:  m_expyrs: -1
m_name:  m_salary: 0 m_designation:  m_expyrs: -1
         */

       //FIX THE SIZE DIFFERENCE
       std::size_t actual_size = std::distance(result2.begin(),itr);
        result2.resize(actual_size);//discard elements beyond last copy
//----------------------------------------------------------------------------------
       /*  EmployeeSmartContainer result3 (data3.size());

        auto itr2 = std::copy_if(
            data3.begin(),
            data3.end(),
            result3.begin(),
            [](EmployeeSmartptr emp)
            {
                return emp->designation() == "Trainee";
            });

        std::size_t actual_size_ptr = std::distance(result3.begin(), itr2);
        result2.resize(actua l_size_ptr); // discard elements beyond last copy
        */
        // result2.resize(count);
        for (auto i : result2)
        {
            std::cout << i << '\n';
        }
       std::cout<<result2.size();
}