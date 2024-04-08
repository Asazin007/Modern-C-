#include "Customer.hpp"

Customer::Customer(std::string m_name_, std::string m_pan_card_, unsigned long int m_phone_, std::shared_ptr<Address> m_add_)
:m_name(m_name_),m_pan_card{m_pan_card_},m_phone{m_phone_},m_add{m_add_}
{
}
std::ostream &operator<<(std::ostream &os, const Customer &rhs) {
    os << "m_name: " << rhs.m_name
       << " m_pan_card: " << rhs.m_pan_card
       << " m_phone: " << rhs.m_phone
       << " m_add: " << *rhs.m_add;
    return os;
}
