#include "Functionalities.h"


void CreateObj(Container &data, ProContainer &data2)
{
    data2.push_back(
        std::make_shared<Project>(
            "4567",
            9456776.89,
            ProjectType::BACKEND
        )
    );
    data2.push_back(
        std::make_shared<Project>(
            "4567",
            8996776.89,
            ProjectType::BACKEND));

    data2.push_back(
        std::make_shared<Project>(
            "4567",
            65456776.89,
            ProjectType::FRONTEND));
            
    data.push_back(std::make_shared<Employee>(
"12334",
3440.09,
EmployeeType::FULLTIME,
std::ref(*data2[0])
    ));
    data.push_back(std::make_shared<Employee>(
        "12334",
        83440.09,
        EmployeeType::FULLTIME,
       std::ref(*data2[1])));
    data.push_back(std::make_shared<Employee>(
        "12334",
        93440.09,
        EmployeeType::FULLTIME,
        std::ref(*data2[2])));
    data.push_back(std::make_shared<Employee>(
        "12334",
        1003440.09,
        EmployeeType::FULLTIME,
        std::ref(*data2[2])));
}

double MaxBudget(Container &data)
{
    double mx=0.0;
    for(Employee_ptr ptr:data){
        if(ptr->project().get().m_getDoun()>mx){
            mx = ptr->project().get().m_getDoun();
        }

    }
    return mx;
}
