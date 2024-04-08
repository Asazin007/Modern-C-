#include "Permit.h"
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "m_serial_number: " << rhs.m_serial_number;
    if(rhs.m_permit_type== PermitType::LEASE)

       os<< " m_permit_type: " <<"Lease";
       else
       os<< "m_permit_type: " <<"Owned";
       os<< " m_permit_duration_left: " << rhs.m_permit_duration_left;
    return os;
}

Permit::Permit(std::string serialnumber, PermitType type, unsigned int durleft)
:m_serial_number{serialnumber},m_permit_type(type),m_permit_duration_left(durleft)
{

}