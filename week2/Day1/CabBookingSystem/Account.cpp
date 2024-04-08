
#include "Account.h"
long int Account::m_counter=100001;

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "m_id: " << rhs.m_id
       << " m_username: " << rhs.m_username;
    return os;
}

Account::Account(const std::string username):m_username(username)
{
m_id=m_counter++;
}
