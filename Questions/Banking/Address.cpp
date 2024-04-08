#include "Address.hpp"
std::ostream &operator<<(std::ostream &os, const Address &rhs)
{
    os << "m_firstline: " << rhs.m_firstline
       << " m_secondline: " << rhs.m_secondline
       << " m_city: " << rhs.m_city
       << " m_state: " << rhs.m_state
       << " m_country: " << rhs.m_country
       << " m_picode: " << rhs.m_picode;
    return os;
}

Address::Address(std::string firstline, std::string secondline, std::string city, std::string state, std::string country, unsigned int pincode)
    : m_firstline{firstline}, m_secondline{secondline}, m_city{city}, m_state{state}, m_country{country}, m_picode{pincode}
{
}

Address::Address(std::string firstline, std::string city, std::string state, std::string country, unsigned int pincode)
: m_firstline{firstline}, m_city{city}, m_state{state}, m_country{country}, m_picode{pincode}
{
}

Address::Address(std::string city, std::string state, std::string country, unsigned int pincode)
:m_city{city}, m_state{state}, m_country{country}, m_picode{pincode}
{
}
