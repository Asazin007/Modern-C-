#include "Device.h"

Device::Device(std::string id, std::string name, float price, float sarvalue, Type type, License_ptr license, Owner_ptr Owner)
:m_id(id),m_name(name),m_price(price),m_sar_value(sarvalue),m_type(type),m_license(license),m_owner{Owner}
{
}
std::ostream &operator<<(std::ostream &os, const Device &rhs)
{
    os << "m_id: " << rhs.m_id
       << " \nm_name: " << rhs.m_name
       << "\n m_price: " << rhs.m_price
       << "\n m_sar_value: " << rhs.m_sar_value;
    if (rhs.m_type== Type::ACCESSORY)
        os << "\n m_type: "
           << "Accesory";
    if (rhs.m_type == Type::MOBILE)
        os << "\n m_type: "
           << "Mobile";
           else
               os << "\n m_type: "
                  << "Workstation";

    os<< " \nm_license: " << rhs.m_license
    << " \nm_owner: " << rhs.m_owner;
    return os;
}
