#include "Dog.h"

Dog::Dog(int legs, bool fly, int speed)
:Animal(legs,fly),m_speed{speed}
{
}
void Dog::who()
{
    std::cout<<"this is Dog\n";
}
void Dog::vioce()
{
    std::cout<<"Dog Barks\n";
}
std::ostream &operator<<(std::ostream &os, const Dog &rhs)
{
    os << "m_speed: " << rhs.m_speed;
    return os;
}
