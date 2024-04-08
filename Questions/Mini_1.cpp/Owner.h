#ifndef OWNER_H
#define OWNER_H

#include<iostream>
class Owner{
private:
    std::string m_registered_name{""};
public: 
    Owner() = default;
    Owner(const Owner &) = delete; // disabled copy constructor
    Owner(Owner &&) = delete; // disabled move constructor brand new in C++11
    Owner &operator=(const Owner &) = delete; // disabled assignment operator
    Owner &operator=(Owner &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Owner() = default;
    Owner(std::string name);

    std::string registeredName() const { return m_registered_name; }
    void setRegisteredName(const std::string &registered_name) { m_registered_name = registered_name; }

    friend std::ostream &operator<<(std::ostream &os, const Owner &rhs);
};

#endif // OWNER_H
