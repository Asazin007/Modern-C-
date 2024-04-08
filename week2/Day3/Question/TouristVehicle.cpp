#include "TouristVehicle.h"

TouristVehicle::TouristVehicle(std::string n, Type type, unsigned int count, float perhour, Permit_ptr permit)
    : m_number{n}, m_type{type}, m_seat_count{count}, m_per_hr_booking_charge{perhour}, m_permit{permit}
{
}
std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs)
{
    os << "m_number: " << rhs.m_number;

    if (rhs.m_type == Type::BIKE)
        os << " m_type: "
           << "Bike";

    if (rhs.m_type == Type::BUS)
        os << " m_type: "
           << "Bus";

    else
        os << " m_type: "
           << "Cab";
    os<< " m_seat_count: " << rhs.m_seat_count
    << " m_per_hr_booking_charge: " << rhs.m_per_hr_booking_charge
    << " m_permit: " << *rhs.m_permit;
    return os;
}
