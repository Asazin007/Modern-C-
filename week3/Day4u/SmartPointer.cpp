/* **********************************Smart Pointer**********************************************

They are wrapper around raw pointers to allow better memory management using RAII design pattern

1) shared_ptr
2) unique_ptr
3)weak_ptr: stalker pointer [shared pointer ----> token] */

#include <iostream>
#include "Employee.h"
#include <memory>
#include <mutex>
#include <thread>
std::mutex mt;
bool allththreads = false;
void ChangeName(std::shared_ptr<Employee> owner2)
{
    std::lock_guard<std::mutex> lg(mt);
    owner2->setName("Gourav");
    std::cout << *owner2 << '\n';
    std::cout << owner2 << "\n";
}

void UpdateSalary(std::shared_ptr<Employee> owner3)
{
    std::lock_guard<std::mutex> lg(mt);
    owner3->setDesignation("Trainer");
    std::cout << *owner3 << '\n';
    std::cout << owner3 << "\n";
}

int main()
{
    std::shared_ptr<Employee> emp = std::make_shared<Employee>("Asim", 234567, "Trainee", 23);
    std::thread t1(ChangeName, emp);
    std::thread t2(UpdateSalary, emp);

    if (std::lock_guard<std::mutex> lg(mt); !allththreads){
        std::cout<<*emp<<'\n';
       
    }
    t1.join();
    t2.join();
}