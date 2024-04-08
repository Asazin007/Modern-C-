#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Gender.h"
#include "Account.h"
#include <iostream>
class CustomerAccount : public Account
{
private:
    std::string m_fullName;
    Gender m_type;

public:
    CustomerAccount() = delete;
    CustomerAccount(const CustomerAccount &) = delete;            // disabled copy constructor
    CustomerAccount(CustomerAccount &&) = delete;                 // disabled move constructor brand new in C++11
    CustomerAccount &operator=(const CustomerAccount &) = delete; // disabled assignment operator
    CustomerAccount &operator=(CustomerAccount &&) = delete;      // disabled assignment move operator brand new in C++11
    CustomerAccount(std::string username, std::string name, Gender type);
    ~CustomerAccount() = default;

    void RegisterAccount() override;

    std::string fullName() const { return m_fullName; }
    void setFullName(const std::string &fullName) { m_fullName = fullName; }

    Gender type() const { return m_type; }

    friend std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs);
};

#endif // CUSTOMER_H
