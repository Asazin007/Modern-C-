#include <iostream>
#include <queue>
#include "Employee.h"
#include "Functionalities.h"
#include <vector>
struct comparator{
    bool operator()(int a, int b){
        return a>b;
    }
};

template<typename T,typename D>
void Display( std::priority_queue<T,std::vector<T>,D>& data){
    while (!data.empty())
    {
        std::cout << data.top() << " ";
        data.pop(); /* code */
    }
}


int main(){
//-----------------using functor
std::vector<int> data {23,12,11,2,3,45,45};
std::priority_queue<int,std::vector<int>,comparator> pq(data.begin(),data.end());

Display<int,comparator>(pq);
//--------------------greater in stl
std::priority_queue<int, std::vector<int>, std::greater<int>> pq2(data.begin(), data.end());

std::cout<<'\n';

Display<int,std::greater<int>>(pq2);
//---------------------------------------using lambda
EmployeeComtainer dataemp;
CreateEmployee(dataemp);

auto comp =[](const Employee& e1, const Employee& e2){
return e1.salary()<e2.salary();
};

std::priority_queue<Employee, std::vector<Employee>, decltype(comp)> pq3(dataemp.begin(), dataemp.end(),comp);

Display<Employee,decltype(comp)>(pq3);
}