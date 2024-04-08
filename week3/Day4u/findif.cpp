#include "Functionalities.h"
template <typename T, typename P>
auto Search(const T &data, const P &predicate)
{

    return std::find_if(
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

    //----------------------------------find-if
    /*
    2)std::find_if
    std::find_if return iterator to first matching objects
    if match is not found , find_if return end iterator


     */

    auto itr = Search<EmployeeComtainer, std::function<bool(const Employee &)>>(data1, [](const Employee &emp)
                                                                                { return emp.designation() == "Trainer"; });

    if (itr != data1.end())
    {

        std::cout << "Found!\n"
                  << *itr;
    }
    else
    {
        std::cout << "Not Found\n";
    }
    auto itr3 =Search<EmployeeSmartContainer, std::function<bool(const EmployeeSmartptr &)>>(data3, [](const EmployeeSmartptr &emp)
                                                                                  { return emp->designation() == "Trainer"; });

    if (itr3 != data3.end())
    {

        std::cout << "Found!\n"
                  << **itr3;
    }
    else
    {
        std::cout << "Not Found\n";
    }
}