#ifndef DEVICE_H
#define DEVICE_H

#include "Type.h"
#include "License.h"
#include "Owner.h"
#include<iostream>
#include <memory>

using License_ptr= std::shared_ptr<License>;
using Owner_ptr= std::shared_ptr<Owner>;
class Device{
private:
    std::string m_id;
    std::string m_name;
    float m_price;
    float m_sar_value{1.0f};
    Type m_type;
    License_ptr m_license;
    Owner_ptr m_owner;   


public: 
    Device() = delete;
    Device(const Device &) = delete; // disabled copy constructor
    Device(Device &&) = delete; // disabled move constructor brand new in C++11
    Device &operator=(const Device &) = delete; // disabled assignment operator
    Device &operator=(Device &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Device() = default;
    Device(std::string id, std::string name, float price, float sarvalue, Type type, License_ptr license, Owner_ptr Owner);

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    float sarValue() const { return m_sar_value; }
    void setSarValue(float sar_value) { m_sar_value = sar_value; }

    Type type() const { return m_type; }
    void setType(const Type &type) { m_type = type; }

    License_ptr license() const { return m_license; }
    void setLicense(const License_ptr &license) { m_license = license; }

    Owner_ptr owner() const { return m_owner; }
    void setOwner(const Owner_ptr &owner) { m_owner = owner; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);

   
   
};

#endif // DEVICE_H
