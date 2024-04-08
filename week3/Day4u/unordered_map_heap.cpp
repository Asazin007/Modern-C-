/*
Hash table
key is integer (employee ID)
value is EMployee on stack
 */

#include <iostream>
#include <unordered_map>
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
    mapData.emplace(101, new Employee("Harshit", 80903.0f, "Trainer", 50));
    mapData.emplace(102,new Employee("Asim", 90903.0f, "Trainee", 24));
    mapData.emplace(104, new Employee("Piyush", 90903.0f, "Traine4", 24));
    mapData.emplace(103, new Employee("Ayush", 90903.0f, "Trainee", 24));
}
int main()
{
    std::unordered_map<int, Employee*> mapData;
    CreateObjects<int, Employee*>(mapData);
    Display<int, Employee*>(mapData);
}