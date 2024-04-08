#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include<iostream>
class Address{
private:
std::string m_firstline;
std::string m_secondline;
std::string m_city;
std::string m_state;
std::string m_country;
unsigned int m_picode;
public: 
    Address() = delete;
    Address(const Address &) = delete; // disabled copy constructor
    Address(Address &&) = delete; // disabled move constructor brand new in C++11
    Address &operator=(const Address &) = delete; // disabled assignment operator
    Address &operator=(Address &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Address() = default;
    Address(std::string firstline,std::string secondline, std::string city, std::string state,std::string country, unsigned int pincode);
    Address(std::string firstline, std::string city, std::string state, std::string country, unsigned int pincode);
    Address( std::string city, std::string state, std::string country, unsigned int pincode);

    std::string firstline() const { return m_firstline; }
    void setFirstline(const std::string &firstline) { m_firstline = firstline; }

    std::string secondline() const { return m_secondline; }
    void setSecondline(const std::string &secondline) { m_secondline = secondline; }

    std::string city() const { return m_city; }
    void setCity(const std::string &city) { m_city = city; }

    std::string state() const { return m_state; }
    void setState(const std::string &state) { m_state = state; }

    std::string country() const { return m_country; }
    void setCountry(const std::string &country) { m_country = country; }

    unsigned int picode() const { return m_picode; }
    void setPicode(unsigned int picode) { m_picode = picode; }

    friend std::ostream &operator<<(std::ostream &os, const Address &rhs);
    
};

#endif // ADDRESS_HPP
