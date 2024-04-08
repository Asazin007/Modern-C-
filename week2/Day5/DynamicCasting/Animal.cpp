#include "Animal.h"

Animal::Animal(int legs, bool canfly)
:m_legs(legs),m_can_fly(canfly)
{
}

std::ostream &operator<<(std::ostream &os, const Animal &rhs) {
    os << "m_legs: " << rhs.m_legs
       << " m_can_fly: " << rhs.m_can_fly;
    return os;
}
