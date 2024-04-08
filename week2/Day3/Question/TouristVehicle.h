#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include "Type.h"
#include "Permit.h"
#include<iostream>
#include <memory>

using Permit_ptr= std::shared_ptr<Permit>;

class TouristVehicle{
private:
std::string m_number;
Type m_type;
unsigned int m_seat_count;
float m_per_hr_booking_charge;
Permit_ptr m_permit;



public: 
    TouristVehicle() = delete;
    TouristVehicle(const TouristVehicle &) = delete; // disabled copy constructor
    TouristVehicle(TouristVehicle &&) = delete; // disabled move constructor brand new in C++11
    TouristVehicle &operator=(const TouristVehicle &) = delete; // disabled assignment operator
    TouristVehicle &operator=(TouristVehicle &&) = delete;	  // disabled assignment move operator brand new in C++11
    TouristVehicle(std::string n, Type type, unsigned int count, float perhour, Permit_ptr permit);
    ~TouristVehicle() = default;

    std::string number() const { return m_number; }
    void setNumber(const std::string &number) { m_number = number; }

    Type type() const { return m_type; }
    void setType(const Type &type) { m_type = type; }

    unsigned int seatCount() const { return m_seat_count; }
    void setSeatCount(unsigned int seat_count) { m_seat_count = seat_count; }

    float perHrBookingCharge() const { return m_per_hr_booking_charge; }
    void setPerHrBookingCharge(float per_hr_booking_charge) { m_per_hr_booking_charge = per_hr_booking_charge; }

    Permit_ptr permit() const { return m_permit; }
    void setPermit(const Permit_ptr &permit) { m_permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
