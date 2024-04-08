#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include <iostream>
#include "Car.h"
class ElectricCar: public Car
{
private:
    /* data */
    int _battery_capacity {0};
    int _time_to_charge {0};
    float _motor_power {0.0f};
    float _max_power {0.0f};
    float _range {0.0f};
public:
    ElectricCar() = default;
    ElectricCar(const ElectricCar &) = delete; // not needed don't create , delete it
    ~ElectricCar() = default;          // default constructor
    // there R 6 special member func , you have to set ,use or not, (enble or disable something)
    ElectricCar(ElectricCar &&) = delete;                 // disable move constructor,this is new features in cpp
    ElectricCar &operator=(const ElectricCar &) = delete; // no loophole
    ElectricCar &operator=(ElectricCar &&) = delete;      // cpp new, delete move assignment operator

    ElectricCar(std::string name, int acceleration, int top_speed, float price,int battery_capacity, float time_to_charge, float motor_power, float max_power, float range);

    float Drive() override; //mark a fuction to override , if func is not right it will give error
    void ShowElectricCarDetails();
    

    int batteryCapacity() const { return _battery_capacity; }
    void setBatteryCapacity(int battery_capacity) { _battery_capacity = battery_capacity; }

    int timeToCharge() const { return _time_to_charge; }
    void setTimeToCharge(int time_to_charge) { _time_to_charge = time_to_charge; }

    float motorPower() const { return _motor_power; }
    void setMotorPower(float motor_power) { _motor_power = motor_power; }

    float maxPower() const { return _max_power; }
    void setMaxPower(float max_power) { _max_power = max_power; }

    float range() const { return _range; }
    void setRange(float range) { _range = range; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);
};



#endif // ELECTRICCAR_H
