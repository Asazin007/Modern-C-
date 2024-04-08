#include "CustomerAccount.h"

std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs)
{
    os << "fullName: " << rhs.m_fullName;
    std::string val;
    if (rhs.type() == Gender::MALE)
    {
        val = "Male";
    }
    else if (rhs.type() == Gender::FEMALE)
    {
        val = "Female";
    }
    else
        val = "Other";

    os << "Gender: " << val;
    return os;
}

CustomerAccount::CustomerAccount(std::string username, std::string name, Gender type) : Account(username), m_fullName(name), m_type(type)
{
}

void CustomerAccount::RegisterAccount()
{
    std::cout << "Account verified via OTP\n";
}
