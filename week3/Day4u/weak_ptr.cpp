/* **********************************Smart Pointer**********************************************

They are wrapper around raw pointers to allow better memory management using RAII design pattern

1) shared_ptr
2) unique_ptr
3)weak_ptr: stalker pointer [shared pointer ----> token] */

#include <iostream>
#include "Employee.h"
#include <memory>
#include <mutex>
#include <chrono>
#include <thread>

void Magic(std::shared_ptr<Employee> owner2)
{

    owner2->setName("Gourav");
    std::cout << *owner2 << '\n';
}

int main(){

    std::shared_ptr<Employee> emp = std::make_shared<Employee>(
        "Asim", 234567, "Trainee", 23);
    std::weak_ptr<Employee> wptr = emp;

    if(wptr.lock()){
        std::cout<<"Owner zinda hai.\n";

    }
    else{
        std::cout<<"Owner mar gya.\n";
    }
    emp.reset();
    if (wptr.lock())
    {
        std::cout << "Owner zinda hai.\n";
    }
    else
    {
        std::cout << "Owner mar gya.\n";
    }
}