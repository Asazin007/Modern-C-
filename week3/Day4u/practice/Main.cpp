#include "Funtionalities.h"


int main(){
EmployeeContainer data;
std::promise<std::string> pr[2];
std::future<std::string> ft[2]
{
    pr[0].get_future(),
    pr[1].get_future()
};

std::thread t(CreateObject, std::ref(data));
t.join();

std::future<bool> isall = std::async(IsallsalAbove40k,std::ref(data));
if(isall.get()){
std::cout<<"All Emp have salary above 40k\n";
}
else
    std::cout << "All Emp does not have salary above 40k\n";

std::future<double> maxsal = std::async(MaxSalary,std::ref(data));
std::cout << "Max Sal is "<<maxsal.get()<<"\n";

std::future<Employee_ptr> ptr = std::async(FindDetails, std::ref(data),std::ref(ft[0]));


pr[0].set_value("Asim");

std::cout<<"Details: "<<*(ptr.get());

std::future<void> res = std::async(FindWithdesig,std::ref(data),std::ref(ft[1]));
pr[1].set_value("Trainee");
res.wait();



}