#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IDnotfoundException.h"

void CreateObjects(Container &data)
{
    data[0] = std::make_shared<Car>("c101",80000000,
                               "Dzire",
                               std::make_shared<Engine>(300,
                                                        110.4f),
                               CarType::SEDAN);
    data[1] = std::make_shared<Car>("c102",
                               1000000,
                               "Inova",
                               std::make_shared<Engine>(360,
                                                        130.4f),
                               CarType::SUV);
    data[2] = std::make_shared<Car>(("c103",
                                1200000,
                                "Wagaor",
                                std::make_shared<Engine>(280,
                                                         100.0f),
                                CarType::HATCHBACK));
}

int TotalHorsepower(const Container &data)
{
    int total = 0;
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    for (const CarPointer c : data)
    {
        total += c->engine()->horsepower();
    }
    return total;
}

bool IsContainerAllCarAbove7lakhs(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    for ( CarPointer c : data)
    {
        if (c->getPrice() <= 700000.0)
            return false;
    }

    return true;
}

Engine *EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    float price = data[0]->getPrice();
    Engine *e = data[0]->engine();
    for (const CarPointer c : data)
    {
        if (c->getPrice() < price)
        {
            price = c->getPrice();
            e = c->engine();
        }
    }

    return e;
}

float AverageEngineHorsePower(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    float avg{0.0f};

    for (const CarPointer c : data)
    {
        avg += c->engine()->horsepower();
    }
    return avg / data.size();
}

float AverageTorque(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    float avg{0.0f};

    for (const CarPointer c : data)
    {
        avg += c->engine()->torque();
    }
    return avg / data.size();
}

std::string FindCarModelById(const Container &data, const std::string carId)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    for (const CarPointer c : data)
    {
        if (c->id() == carId)
        {
            return c->model();
        }
    }
    throw IDnotfoundException("Id not found");
    return std::string();
}

void DisplayData(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is empty");
    }
    for (const CarPointer c : data)
    {
        std::cout << *c;
    }
}
