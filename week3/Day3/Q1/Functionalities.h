#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <array> //STL
#include "Car.h"
#include<memory>

using Container = std::array<const Car*, 3>;
using CarPointer = std::shared_ptr<Car>;
void CreateObjects(Container& data);


int TotalHorsepower(const Container& data);
/*
do all cars in the container have price above 7 lakhs
*/
bool IsContainerAllCarAbove7lakhs(const Container& data);

Engine* EnginePointerToMinPriceCar(const Container& data);

/*
find the avg torque of the engine
*/
float AverageTorque(const Container& data);

std::string FindCarModelById(const Container& data, const std::string carId);

void DisplayData(const Container& data);
#endif // FUNCTIONALITIES_H
