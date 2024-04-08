#include "Car.h"
#include "Engine.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_id: " << rhs._id
       << " price: " << rhs._price
       << " _model: " << rhs._model
       << " _engine: " << *rhs._engine;
    return os;
}
Car::Car(std::string id, std::string model, EnginePtr engine, CarType c)
    : _id{id}, _model{model}, _engine{engine}, _type{c}
{
}

Car::Car(std::string id, float price, std::string model, EnginePtr engine, CarType c)
    : Car(id, model, engine, c) // constructor delegation:use multiple constructor in same class
{
    _price = price;

    // but not be able to use member func list intitializATION
}
