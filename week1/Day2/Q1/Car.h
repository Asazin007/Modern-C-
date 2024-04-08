#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Engine.h"
#include "CarType.h"
#include <memory>
using EnginePtr = std::shared_ptr<Engine>;

class Car
{
private:
    std::string _id;
    float _price;
    std::string _model;
    EnginePtr _engine;
    CarType _type;

public:
    Car(/* args */) = delete;
    Car(const Car &) = delete;
    Car(Car &&) = delete;
    Car &operator=(const Car &) = delete;
    Car &&operator=(Car &&) = delete;
    ~Car() = default;
    Car(std::string id, float price, std::string model, EnginePtr engine, CarType c);
    Car(std::string id, std::string model, EnginePtr engine, CarType c);

    std::string id() const { return _id; }

    float getPrice() const { return _price; }
    void setPrice(float price_) { _price = price_; }

    std::string model() const { return _model; }

    EnginePtr engine() const { return _engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
