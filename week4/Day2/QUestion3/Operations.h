#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <future>
#include <vector>
#include <optional>
#include <algorithm>
#include <numeric>
#include "CabRide.h"
#include "Exception.h"
#include <array>
#include <unordered_map>

class Operations;
using op_ptr = std::shared_ptr<Operations>;
using CarRide_ptr = std::shared_ptr<CabRide>;
using Driver_ptr = std::shared_ptr<Driver>;
using CarRideCon = std::unordered_map<std::string ,CarRide_ptr>;
using DriverCon = std::vector<Driver_ptr>;

class Operations
{
private:
    CarRideCon m_data;
    DriverCon m_drivers;

    static op_ptr m_soloObj; // static object
    // private contruct

    Operations() = default;

public:
    Operations(const Operations &) = delete;            // disabled copy constructor
    Operations(Operations &&) = delete;                 // disabled move constructor brand new in C++11
    Operations &operator=(const Operations &) = delete; // disabled assignment operator
    Operations &operator=(Operations &&) = delete;      // disabled assignment move operator brand new in C++11
    ~Operations() = default;
    
    static op_ptr getObj();

    void CreateObjects();
    PaymentMode PaymentmodeID(Vtype_id &id);
    std::array<RideType, 2> MAXMINRideType();
    std::vector<std::string> PickofN(const int &n);
    DriverCon NDrivers(const int &n);

    DriverCon drivers() const { return m_drivers; }
};

#endif // OPERATIONS_H
