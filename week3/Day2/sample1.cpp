/*
TaxPayers: Employees, BusinessOwners
          TaxPayers
              |
Employees          BusinessOwner

Employee* ptr1;
BusinessOwner* ptr2;
TaxPayer* arr[2] {ptr1,ptr2}

Variant can be use if no of child classes are fixed and you dont want vtable overhead
 Algebraic data types(ADT) -
 */
/* 
variant is either of type Employee pointer or BusinessOwner pointer
 */

#include <variant>
#include <iostream>
#include <array>

class BusinessOwner
{
private:
    std::string m_name;
    std::string m_companyGSTno;
    float m_revenue;
    float m_expenses;

public:
    BusinessOwner(std::string name, std::string gstno, float rev, float expense)
        : m_name{name}, m_companyGSTno{gstno}, m_revenue{rev}, m_expenses{expense} {}
    float CalcTaxAmount() { return 0.3f * (m_revenue - m_expenses); }
    ~BusinessOwner() = default;
    std::string name() const { return m_name; }
};

class Employee
{
private:
    std::string m_name;
    float m_salary;
    /* data */


public:
    Employee(std::string name, float sal)
        : m_name{name}, m_salary{sal} {}
    ~Employee() = default;
    std::string name() const { return m_name; }
};

using Vtype = std::variant<Employee *, BusinessOwner *>;
using Container = std::array<Vtype, 2>;

void CommanAction(Container &arr)
{
    for (Vtype v : arr)
    //&&-> template parameter for lamda
        std::visit(
            [](auto &&val)
            {
                std::cout << val->name() << '\n';
            },
            v);
}

void UnCommonFunction(Container& arr){


for(Vtype v: arr){

    if(std::holds_alternative<BusinessOwner* >(v)){
       BusinessOwner* ow= std::get<1>(v);
       std::cout<< "Tax Amount : " <<ow->CalcTaxAmount();
    }
}


}

/* 

for each vtype(variant) called "v",
a) open variant and check if v holds an alternative of type Businessowner*
b) if yes , get data from  slot 1 of the variant (because slot 1 is for BussinessOnwer*) ,
Now , save this to a variable and access revennue
 */

int main()
{
    Employee *emp = new Employee("Harshit", 9000000.f);
    BusinessOwner *bussiness = new BusinessOwner("XYZ", "234dc", 100000040.f, 50342.0f);

    Container arr{emp, bussiness};
    CommanAction(arr);
    UnCommonFunction(arr);
}
/*
scneario 1: same function in both variant , we can easily call getter
scenario 2: if not, open the variant and check whether it is present or not , if present call , else go to next one.

 */
