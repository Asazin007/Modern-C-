#include "Employee.h"
#include <variant>
#include <memory>
#include <thread>

class Freelancer
{
private:
    /* data */
    std::string m_name;
    double m_salary;
    std::string m_role;
public:
    Freelancer(std::string name, double salary, std::string role)
    :m_name{name}, m_salary{salary},m_role{role} {}
    ~Freelancer() {}

    std::string name() const { return m_name; }

    double salary() const { return m_salary; }

    std::string role() const { return m_role; }
};



using Employee_ptr = std::shared_ptr<Employee>;
using Freelancer_ptr = std::shared_ptr<Freelancer>;
using varContainer = std::variant<Employee_ptr, Freelancer_ptr>;

void common(varContainer data[] ,int n) {
    for(int i=0;i<n;i++)
{std::visit(
[](auto&& val){
std::cout<<"Name : "<< val->name()<<"\nSalary : "<<val->salary()<<'\n';
},data[i]
);}
}

void uncommon(varContainer (&data)[2],int n) {
    for (int i = 0; i < n; i++){
        if(std::holds_alternative<Employee_ptr>(data[i])){
            Employee_ptr e = std::get<0>(data[i]);
            std::cout<<"Designation : "<<e->designation();
        }
    }
}

int main()
{
    Employee_ptr eptr = std::make_shared<Employee>("Asim",234567,"Trainee");
    Freelancer_ptr fptr = std::make_shared<Freelancer>("Yuvraj",3234,"Web Devloper");
    varContainer v[2]{eptr,fptr};
    
    std::thread t1(common,v,2);
    std::thread t2(uncommon,std::ref(v),2);
    t1.join();
    t2.join();

    

}