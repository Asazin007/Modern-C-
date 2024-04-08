#ifndef DRIVER_H
#define DRIVER_H

#include<iostream>
#include "DriverRating.h"
class Driver{
private:
    std::string m_driver_id;
    DriverRating m_driver_rat;
    

public: 
    Driver() = delete;
    Driver(const Driver &) = delete; // disabled copy constructor
    Driver(Driver &&) = delete; // disabled move constructor brand new in C++11
    Driver &operator=(const Driver &) = delete; // disabled assignment operator
    Driver &operator=(Driver &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Driver() = default;
    Driver(std::string id, DriverRating rat);

    std::string driverId() const { return m_driver_id; }

    DriverRating driverRat() const { return m_driver_rat; }

    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
};

#endif // DRIVER_H
