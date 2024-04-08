#include "Owner.h"

Owner::Owner(std::string name)
{
}
std::ostream &operator<<(std::ostream &os, const Owner &rhs) {
    os << "m_registered_name: " << rhs.m_registered_name;
    return os;
}
