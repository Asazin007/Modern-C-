#ifndef CABRIDE_H
#define CABRIDE_H

#include<iostream>
#include "Driver.h"
#include "RideType.h"
#include "PaymentMode.h"
#include <memory>
#include <functional>
#include <variant>

using Vtype_id= std::variant<std::string, int>;
using Driver_ref = std::reference_wrapper<Driver>;

class CabRide
{
private:
Vtype_id m_id;
RideType m_ridetype;
PaymentMode m_paymentmode;
float m_fare;
std::string m_drop_loc;
std::string m_pickup_loc;
Driver_ref m_cab_driver;
    
public: 
    CabRide() = delete;
    CabRide(const CabRide &) = delete; // disabled copy constructor
    CabRide(CabRide &&) = delete; // disabled move constructor brand new in C++11
    CabRide &operator=(const CabRide &) = delete; // disabled assignment operator
    CabRide &operator=(CabRide &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~CabRide() = default;
    CabRide(Vtype_id id, RideType rtype, PaymentMode mode, float fare, std::string drop,std::string pickup, Driver_ref ref);

    Vtype_id id() const { return m_id; }
    void setId(const Vtype_id &id) { m_id = id; }

    RideType ridetype() const { return m_ridetype; }
    void setRidetype(const RideType &ridetype) { m_ridetype = ridetype; }
    std::string stringride() const{
        std::string s;
        if(this->m_ridetype==RideType::LOCAL) s="Local";
        if (this->m_ridetype == RideType::OUTSTATION) s = "Outstation";
        else s= "Rent";
        return s;
    }



    PaymentMode paymentmode() const { return m_paymentmode; }
    std::string stringmode() const{
        std::string s;
        if(this->m_paymentmode==PaymentMode::CASH)  s="Cash";
        if (this->m_paymentmode == PaymentMode::CARD) s="CARD";
        if (this->m_paymentmode == PaymentMode::UPI) s="UPI";
        else s= "Wallet";
        return s;
    }

    float fare() const { return m_fare; }

    std::string dropLoc() const { return m_drop_loc; }

    std::string pickupLoc() const { return m_pickup_loc; }

    std::reference_wrapper<Driver> cabDriver() const { return m_cab_driver; }

    friend std::ostream &operator<<(std::ostream &os, const CabRide &rhs);
};

#endif // CABRIDE_H
