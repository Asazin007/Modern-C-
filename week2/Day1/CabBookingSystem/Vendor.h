#ifndef VENDOR_H
#define VENDOR_H

#include "Account.h"
#include "Driver.h"
#include <vector>
#include<iostream>
#include<memory>
using drivercontainer = std::vector<std::shared_ptr<Driver>> ;
using cabunitcontainer= std::vector<std::shared_ptr<CabUnit>>;
class Vendor : public Account
{
private:
    std::string m_vendorName;
    drivercontainer m_driver{};
    cabunitcontainer m_cabUnits{};
public: 
    Vendor() = delete;
    Vendor(const Vendor &) = delete; // disabled copy constructor
    Vendor(Vendor &&) = delete; // disabled move constructor brand new in C++11
    Vendor &operator=(const Vendor &) = delete; // disabled assignment operator
    Vendor &operator=(Vendor &&) = delete;	  // disabled assignment move operator brand new in C++11
    Vendor(std::string username, std::string vendorname);
    Vendor(std::string username, std::string vendorname,const drivercontainer& drivers, const cabunitcontainer& cabunits);

    void RegisterAccount() override;
    ~Vendor() = default;

    friend std::ostream &operator<<(std::ostream &os, const Vendor &rhs);
};

#endif // VENDOR_H
