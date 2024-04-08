#include "DateTime.h"

DateTime::DateTime(std::string day, Month month, std::string year,std::string hours, std::string min)
:m_day(day),m_month(month),m_year(year),m_hours(hours),m_min(min)
{}

std::string DateTime::getMonthString() const
{
    std::string month;
    switch (this->m_month)
    {
    case Month::JANUARY:
        month = "January";
        break;
    case Month::FEBRUARY:
        month = "February";

        break;
    case Month::MARCH:
        month = "March";
        break;
    case Month::APRIL:
        month = "April";
        break;
    case Month::MAY:
        month = "May";
        break;
    case Month::JUNE:
        month = "June";
        break;
    case Month::JULY:
        month = "July";
        break;
    case Month::AUGUST:
        month = "August";
        break;
    case Month::SEPTEMBER:
        month = "September";
        break;
    case Month::OCTOBER:
        month = "October";
        break;
    case Month::NOVEMBER:
        month = "November";
        break;
    case Month::DECEMBER:
        month = "December";
        break;
    default:
        month = "Invalid month";
    }

    return month;
}

std::ostream &operator<<(std::ostream &os, const DateTime &rhs) {

    os << "m_day: " << rhs.m_day
       << " m_month: " << rhs.getMonthString()
       << " m_year: " << rhs.m_year
       << " m_hours: " << rhs.m_hours
       << " m_min: " << rhs.m_min;
    return os;
}

