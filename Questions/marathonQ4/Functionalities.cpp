#include "Functionalities.h"
#include "ElectricCar.h"
void CreateObjects(std::vector<Car *> &data)
{
    data.push_back(new ElectricCar("NexonEv", 80, 150, 1870000.90f, 33, 2, 300, 600, 320));
    data.push_back(new ElectricCar("XuvEv", 70, 160, 1670000.90f, 36, 2, 400, 600, 420));
}   

void DeleteObjets(std::vector<Car *> &data)
{
    for (Car *p : data)
    {
        delete p;
    }
}
