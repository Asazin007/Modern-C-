#include "Functionalities.hpp"
void createObjects(Container &data)
{
    data.emplace("c101", std::make_shared<Car>(CarType::SEDAN, "c101", 779000.0f, "Dzire",
                                               std::make_shared<Engine>(111.0f, 300)));
    data.emplace("c102", std::make_shared<Car>(CarType::SUV, "c102", 989000.0f, "Fortuner",
                                               std::make_shared<Engine>(811.0f, 600)));
    data.emplace("c103", std::make_shared<Car>(CarType::HATCHBATCH, "c103", 6690009.56f, "Wagnor",
                                               std::make_shared<Engine>(119.0f, 260)));
}

float TotalHorsePower(const Container &data)
{
    if (data.empty())
    {
        EmptyContainerException("Data is empty\n");
    }

    // for (auto &[key, value] : data)
    // {
    //     total+=value->getEngine()->getHorsePower();
    // }
    return std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float answer_upto_date, const std::pair<std::string, Car_ptr> &mp)
        {
            return answer_upto_date + mp.second->getEngine()->getHorsePower();
        });
}

bool isContainerAllCarAbove700000(const Container &data)
{
    if (data.empty())
    {
        EmptyContainerException("Data is empty\n");
    }
    // for (auto & [ key, value ] : data)
    // {
    //     if (value->price() <= 700000.0f)
    //         return false;
    // }
    return std::all_of(data.begin(), data.end(), [](const std::pair<std::string, Car_ptr> &mp)
                       { return mp.second->price() >= 700000.0f; });
}

Engine_ptr EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty())
    {
        EmptyContainerException("Data is empty\n");
    }
    auto itr = std::min_element(
        data.begin(), data.end(), [](const std::pair<std::string, Car_ptr> &mp, const std::pair<std::string, Car_ptr> &mp2)
        { return mp2.second->price() < mp.second->price(); });
    return (*itr).second->getEngine();
}

float AverageEngineTorque(const Container &data)
{
    if (data.empty())
    {
        EmptyContainerException("Data is empty\n");
    }
    int count = 0;
    float avg = std::accumulate(data.begin(), data.end(), 0.0f, [&count](float ans, const std::pair<std::string, Car_ptr> &mp)
                                {
    if(mp.second->getEngine()){
    count++;
    return ans + mp.second->getEngine()->getTorque();
    }
    return 0.0f;
    } );
    return (avg / static_cast<float>(count));
}

std::string FindCarModelById(const Container &data, const std::string carId)
{
    if (data.empty())
    {
        EmptyContainerException("Data is empty\n");
    }

    std::string id = "";

    auto itr = std::find_if(data.begin(), data.end(), [&carId](const std::pair<std::string, Car_ptr> &mp)
                            { return mp.second->getCarId() == carId; });
    if (itr != data.begin())
    {
        id = (*itr).second->getCarId();
    }
    else
    throw IdNotFound("Id not found\n");

        return id;
}
