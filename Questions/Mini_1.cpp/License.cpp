#include "License.h"

int License::counter=1000;


std::ostream &operator<<(std::ostream &os, const License &rhs) {
    os << "m_license_no: " << rhs.m_license_no<<std::endl;
    if(rhs.m_license_type==LicenseType::OWNED)
       os<< " m_license_type: " << "owned\n";
       else
           os << " m_license_type: "
              << "Rented\n";
    return os;
}

License::License(LicenseType type)
:m_license_type{type}
{
  m_license_no=++counter;  
}