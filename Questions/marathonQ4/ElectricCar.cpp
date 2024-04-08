#include "ElectricCar.h"

ElectricCar::ElectricCar(std::string name, int acceleration, int top_speed, float price, int battery_capacity, float time_to_charge, float motor_power, float max_power, float range)
:Car(name, acceleration, top_speed, price), _battery_capacity(battery_capacity), _time_to_charge(time_to_charge), _motor_power(motor_power), _max_power(max_power), _range(range)
{}

float ElectricCar::Drive()
{
    return 0.0f;
}

void ElectricCar::ShowElectricCarDetails()
{
    std::cout << " Battery_capacity: " << _battery_capacity
              << " Time_to_charge: " << _time_to_charge
              << " Motor_power: " << _motor_power
              << " Max_power: " << _max_power
              << "Range" << _range << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs)
{
    os << static_cast<const Car &>(rhs)
       << " Battery_capacity: " << rhs._battery_capacity
       << " Time_to_charge: " << rhs._time_to_charge
       << " Motor_power: " << rhs._motor_power
       << " Max_power: " << rhs._max_power
       <<"Range" <<rhs._range<<std::endl;
    return os;
}
