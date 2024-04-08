#include <iostream>
#include "Employee.h"
#include "Functionalities.h"

template <typename T, typename E>
void Display(const T & data){
for(E i: data){
std::cout<<i<<'\n';
}
}

template <typename T, typename E,typename X>
X coutsal = [](const T &data) {
return std::count_if(data.begin(),data.end(),[](const E & emp){
    return emp.salary()>40000.0f;
});

};

int main(int argc, char const *argv[])
{
    EmployeeComtainer data;
    CreateEmployee(data);
    Display<EmployeeComtainer,Employee>(data);
    std::cout<< coutsal<EmployeeComtainer,Employee, std::function<int(const EmployeeComtainer&)>>(data);
    /* code */
    return 0;
}
