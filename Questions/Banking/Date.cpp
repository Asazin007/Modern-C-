#include "Date.hpp"

Date::Date(int month, int year)
:m_month(month),m_year(year)
{
}
std::ostream &operator<<(std::ostream &os, const Date &rhs) {
    os << "m_month: " << rhs.m_month
       << " m_year: " << rhs.m_year;
    return os;
}
