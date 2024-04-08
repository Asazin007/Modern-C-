#ifndef PERMIT_H
#define PERMIT_H

#include "PermitType.h"
#include<iostream>
class Permit{
private:
std::string m_serial_number;
PermitType m_permit_type;
unsigned int m_permit_duration_left;

public: 
    Permit() = delete;
    Permit(const Permit &) = delete; // disabled copy constructor
    Permit(Permit &&) = delete; // disabled move constructor brand new in C++11
    Permit &operator=(const Permit &) = delete; // disabled assignment operator
    Permit &operator=(Permit &&) = delete;	  // disabled assignment move operator brand new in C++11
    Permit(std::string serialnumber, PermitType type, unsigned int durleft);
    ~Permit() = default;

    PermitType permitType() const { return m_permit_type; }
    void setPermitType(const PermitType &permit_type) { m_permit_type = permit_type; }

    std::string serialNumber() const { return m_serial_number; }
    void setSerialNumber(const std::string &serial_number) { m_serial_number = serial_number; }

    unsigned int permitDurationLeft() const { return m_permit_duration_left; }
    void setPermitDurationLeft(unsigned int permit_duration_left) { m_permit_duration_left = permit_duration_left; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
