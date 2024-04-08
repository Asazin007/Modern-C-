#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "Address.hpp"
#include <memory>
#include <iostream>
class Customer
{
private:
    std::string m_name;
    std::string m_pan_card;
    unsigned long int m_phone;
    std::shared_ptr<Address> m_add;

public:
    Customer() = delete;
    Customer(const Customer &) = delete;            // disabled copy constructor
    Customer(Customer &&) = delete;                 // disabled move constructor brand new in C++11
    Customer &operator=(const Customer &) = delete; // disabled assignment operator
    Customer &operator=(Customer &&) = delete;      // disabled assignment move operator brand new in C++11
    Customer(std::string m_name_, std::string m_pan_card_, unsigned long int m_phone_, std::shared_ptr<Address> m_add_);
    ~Customer() = default;

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    std::string panCard() const { return m_pan_card; }
    void setPanCard(const std::string &pan_card) { m_pan_card = pan_card; }

    unsigned long int phone() const { return m_phone; }
    void setPhone(unsigned long int phone) { m_phone = phone; }

    std::shared_ptr<Address> add() const { return m_add; }
    void setAdd(const std::shared_ptr<Address> &add) { m_add = add; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
};

#endif // CUSTOMER_HPP
