#include "DeiselCar.h"

DeiselCar::DeiselCar(std::string name, float milage, float maxpower, float renge, float fuelcap):
m_name{name},m_milage{milage},m_max_power{maxpower},m_range{renge},m_fuel_capacity{fuelcap}
{
}
std::ostream &operator<<(std::ostream &os, const DeiselCar &rhs) {
    os << "m_name: " << rhs.m_name
       << " m_milage: " << rhs.m_milage
       << " m_max_power: " << rhs.m_max_power
       << " m_range: " << rhs.m_range
       << " m_fuel_capacity: " << rhs.m_fuel_capacity;
    return os;
}
