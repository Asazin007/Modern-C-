#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "TouristVehicle.h"
#include <functional>
#include <list>
#include "EmptyContainerException.h"
#include "OutOfBoundException.h"
/* A function to create at least 3 TouristVehicle instances on the heap and store pointers to these instances in
a list container. */
using TouristVehicle_ptr= std::shared_ptr<TouristVehicle>;
using container = std::list<TouristVehicle_ptr>;

void CreateObject(container & data);

/*
A function to find and return pointers to first N in instances of TouristVehicle in a container that satisfy both
of the following conditions
○ _seat_count of the TouristVehicle instance is at least 4.
○ _permit instance's _permit_type is LEASE. */

container FirstNPointer(container & data, int n);

/*
A function to find and return the average _per_hour_booking_charge value for all TouristVehicle
instances in the container that are of type matching */
float AvgPerhourBooking(container & data);

/*
A function to find the TouristVehicle instance for which _per_hour_booking_charge is maximum and
return its _permit instance's _serial_number. */

TouristVehicle_ptr MaxPerhourBooking(container& data);

/*
A function to return the first N instances of TouristVehicle in the container */

container FirstNTouristVeh(container& data,int n);

#endif // FUNCTIONALITIES_H
