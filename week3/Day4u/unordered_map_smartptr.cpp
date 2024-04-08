/*
Hash table
key is integer (employee ID)
value is EMployee on stack
 */

#include <iostream>
#include <unordered_map>
#include <memory>
#include "Employee.h"

template <typename K, typename V>

void Display(const std::unordered_map<K, V> &mapData)
{
    for (auto &[key, value] : mapData)
    {
        std::cout << key << "\t" << *value << '\n';
    }
}
template <typename K, typename V>
void CreateObjects(std::unordered_map<K, V> &mapData)
{
    mapData.emplace(101, std::make_shared<Employee>("Harshit", 80903.0f, "Trainer", 50));
    mapData.emplace(102, std::make_shared<Employee>("Asim", 90903.0f, "Trainee", 24));
    mapData.emplace(104, std::make_shared<Employee>("Piyush", 90903.0f, "Traine4", 24));
    mapData.emplace(103, std::make_shared<Employee>("Ayush", 90903.0f, "Trainee", 24));
}
int main()
{
    std::unordered_map<int, std::shared_ptr<Employee>> mapData;
    CreateObjects<int,std::shared_ptr<Employee>> (mapData);
    Display<int, std::shared_ptr<Employee>>(mapData);
}