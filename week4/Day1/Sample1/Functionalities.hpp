#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include "Car.hpp"
#include "EmptyContainer.hpp"
#include "IdNotFound.hpp"
#include <memory>
#include <array>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using Car_ptr = std::shared_ptr<Car>;
using Container = std::unordered_map<std::string,Car_ptr> ; // MODERN CPP Feature

void createObjects(Container &data);



//  Input: Container
//  output: int
float TotalHorsePower(const Container &data);
/*
    Is this condition true or false:
    All cars in the container have a price above 700000
*/
bool isContainerAllCarAbove700000(const Container &data);
/*
    return the _engine pointer of the Car whose price is lowest
    If multiple Car instances have the same minimum, consider first minimum found

*/

Engine_ptr EnginePointerToMinPriceCar(const Container &data);

/*
    find the average torque for engines in the Car Container

*/

float AverageEngineTorque(const Container &data);

/*
    A function to print the model name  of the car whose _id is passed as a parameter is passed
*/

std::string FindCarModelById(const Container &data, const std::string carId);

#endif // FUNCTIONALITIES_HPP
