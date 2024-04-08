#ifndef DEISELDeiselCar_H
#define DEISELDeiselCar_H

#include<iostream>
class DeiselCar{
private:
    std::string m_name;
    float m_milage;
    float m_max_power;
    float m_range;
    float m_fuel_capacity;

public: 
    DeiselCar() = delete;
    DeiselCar(const DeiselCar &) = delete; // disabled copy constructor
    DeiselCar(DeiselCar &&) = delete; // disabled move constructor brand new in C++11
    DeiselCar &operator=(const DeiselCar &) = delete; // disabled assignment operator
    DeiselCar &operator=(DeiselCar &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~DeiselCar() = default;
    DeiselCar(std::string name, float milage, float maxpower, float renge, float fuelcap);

    float fuelCapacity() const { return m_fuel_capacity; }
    void setFuelCapacity(float fuel_capacity) { m_fuel_capacity = fuel_capacity; }

    float range() const { return m_range; }
    void setRange(float range) { m_range = range; }

    float maxPower() const { return m_max_power; }
    void setMaxPower(float max_power) { m_max_power = max_power; }

    float milage() const { return m_milage; }
    void setMilage(float milage) { m_milage = milage; }

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    friend std::ostream &operator<<(std::ostream &os, const DeiselCar &rhs);
};

#endif // DEISELDeiselCar_H
