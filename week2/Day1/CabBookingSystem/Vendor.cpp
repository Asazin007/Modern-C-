#include "Vendor.h"

Vendor::Vendor(std::string username, std::string vendorname)
:Account(username),m_vendorName{vendorname}
{}

Vendor::Vendor(std::string username, std::string vendorname, const drivercontainer &drivers, const cabunitcontainer &cabunits)
:Vendor(username, vendorname)
{

    m_driver=drivers;
     m_cabUnits = cabunits ;
}


void Vendor::RegisterAccount()
{
    std::cout<<"Vendor verified of official norms.\n";
}
std::ostream &operator<<(std::ostream &os, const Vendor &rhs)
{
    os << static_cast<const Account &>(rhs)
       << " m_vendorName: " << rhs.m_vendorName;
    return os;
}
