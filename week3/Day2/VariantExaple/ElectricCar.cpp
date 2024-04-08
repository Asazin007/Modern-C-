#include "ElectricCar.h"
std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs) {
    os << "_battery_capacity: " << rhs._battery_capacity
       << " _time_to_charge: " << rhs._time_to_charge
       
       << " _max_power: " << rhs._max_power
       << " _range: " << rhs._range;
    return os;
}

ElectricCar::ElectricCar(std::string name, int battery_cap, int timetochare, float maxpow, float range)
    : m_name{name}, _battery_capacity{battery_cap}, _time_to_charge{timetochare}, _max_power{maxpow}, _range{range}
{
}