/*
int _battery_capacity {0};
    int _time_to_charge {0};
    float _motor_power {0.0f};
    float _max_power {0.0f};
    float _range {0.0f};
 */

#ifndef ELECTRICElectricCar_H
#define ELECTRICElectricCar_H

#include <iostream>
class ElectricCar
{
private:
    std::string m_name;
    int _battery_capacity{0};
    int _time_to_charge{0};
    
    float _max_power{0.0f};
    float _range{0.0f};

public:
    ElectricCar() = delete;
    ElectricCar(const ElectricCar &) = delete;            // disabled copy constructor
    ElectricCar(ElectricCar &&) = delete;                 // disabled move constructor brand new in C++11
    ElectricCar &operator=(const ElectricCar &) = delete; // disabled assignment operator
    ElectricCar &operator=(ElectricCar &&) = delete;      // disabled assignment move operator brand new in C++11
    ~ElectricCar() = default;
    ElectricCar(std::string name, int battery_cap, int timetochare, float maxpow, float range);

    int batteryCapacity() const { return _battery_capacity; }
    void setBatteryCapacity(int battery_capacity) { _battery_capacity = battery_capacity; }

    int timeToCharge() const { return _time_to_charge; }
    void setTimeToCharge(int time_to_charge) { _time_to_charge = time_to_charge; }

    float maxPower() const { return _max_power; }
    void setMaxPower(float max_power) { _max_power = max_power; }

    float range() const { return _range; }
    void setRange(float range) { _range = range; }

    std::string name() const { return m_name; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);
};

#endif // ELECTRICElectricCar_H
