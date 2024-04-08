#include <iostream>
#include <vector>
#include <memory>
#include <functional>


class Employee
{
private:
    int m_id;
    std::string m_name;
    float m_salary;

public:
    Employee() = delete;
    Employee(const Employee &) = delete;            // disabled copy constructor
    Employee(Employee &&) = delete;                 // disabled move constructor brand new in C++11
    Employee &operator=(const Employee &) = delete; // disabled assignment operator
    Employee &operator=(Employee &&) = delete;      // disabled assignment move operator brand new in C++11
    ~Employee() = default;
    Employee(int id, std::string name, float salary)
        : m_id(id), m_name(name), m_salary(salary) {}
    float operator+(const Employee &rhs)
    {
        return m_salary + rhs.m_salary;
    }
    void operator()()
    {
        std::cout << "tax for this emoloyee at 10%: " << m_salary * 0.1f;
    }

    float salary() const { return m_salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};
using Employee_ptr= std::shared_ptr<Employee>;

void Adaptor(const std::vector<Employee_ptr> & data, std::function<bool(Employee_ptr)> predicate){
for(Employee_ptr ptr: data){
    if(predicate(ptr))
    std::cout<<*ptr<<"\n";
}

}


int main(){
    std::vector<Employee_ptr> data{

        std::make_shared<Employee>(101, "Asim", 29393.0f),
        std::make_shared<Employee>(102, "Harshit", 999999.0f)};

    Adaptor(data,
            [](Employee_ptr e)
            {
                if (e)
                    return e->salary() > 8000.0f;
                return false;
            });


}

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "m_id: " << rhs.m_id
       << " m_name: " << rhs.m_name
       << " m_salary: " << rhs.m_salary;
    return os;
}
