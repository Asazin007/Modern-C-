#include "Driver.h"
std::ostream &operator<<(std::ostream &os, const Driver &rhs) {
    os << "m_driver_id: " << rhs.m_driver_id;
    if(rhs.m_driver_rat==DriverRating::STAR_1)
       os<< "\n m_driver_rat: " << "1 Star";

    if (rhs.driverRat() == DriverRating::STAR_2)
        os<< "\n m_driver_rat: "
        << "2 Star";
        else
            os << "\n m_driver_rat: "
               << "3 Star";
    return os;
}

Driver::Driver(std::string id, DriverRating rat)
:m_driver_id{id}, m_driver_rat{rat}
{
}