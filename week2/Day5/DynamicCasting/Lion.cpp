#include "Lion.h"

Lion::Lion(int legs, bool fly, int speed)
:Animal(legs,fly),m_speed{speed}
{
}
void Lion::vioce()
{
    std::cout<<"Lion Roars\n";
}
std::ostream &operator<<(std::ostream &os, const Lion &rhs)
{
    os << static_cast<const Animal &>(rhs)
       << " m_speed: " << rhs.m_speed;
    return os;
}
