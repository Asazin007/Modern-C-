#include "Functionalities.h"

void CreateObject(container &data)
{
    data.push_back(std::make_shared<TouristVehicle>(
        "12345",
        Type::BIKE,
        2,
        200.0f,
        std::make_shared<Permit>(
            "12345e",
            PermitType::LEASE,
            12)));

    data.push_back(std::make_shared<TouristVehicle>(
        "12346",
        Type::BUS,
        22,
        2000.0f,
        std::make_shared<Permit>(
            "12345e",
            PermitType::LEASE,
            128)));

    data.push_back(std::make_shared<TouristVehicle>(
        "12347",
        Type::CAB,
        4,
        500.0f,
        std::make_shared<Permit>(
            "12345e",
            PermitType::OWNED,
            12)));

    data.push_back(std::make_shared<TouristVehicle>(
        "12348",
        Type::CAB,
        6,
        800.0f,
        std::make_shared<Permit>(
            "12345e",
            PermitType::LEASE,
            62)));
}
// void Adaptor(std::list<TouristVehicle_ptr> d, std::function<bool(TouristVehicle_ptr)>){

// }

container FirstNPointer(container &data, int n)
{
    if (data.empty())
        throw EmptyContainerException("Container is Empty\n");
    if (n > data.size() || n <= 0)
        throw OutOfBoundException("Value of N is not valid\n");

    container firstNPointer;
    /* ○ _seat_count of the TouristVehicle instance is at least 4.
    ○ _permit instance's _permit_type is LEASE.  */
    for (TouristVehicle_ptr ptr : data)
    {
        if (n == 0)
            return firstNPointer;
        if (ptr->seatCount() >= 4 && ptr->permit()->permitType() == PermitType::LEASE)
        {
            firstNPointer.push_back(ptr);
            n--;
        }
    }

    return firstNPointer;
}

float AvgPerhourBooking(container &data)
{
    if (data.empty())
        throw EmptyContainerException("Container is Empty\n");
    float avg = 0.0f;

    for (TouristVehicle_ptr ptr : data)
    {
        avg += ptr->perHrBookingCharge();
    }
    return avg / data.size();
}

TouristVehicle_ptr MaxPerhourBooking(container &data)
{
    if (data.empty())
        throw EmptyContainerException("Container is Empty\n");
    float maxphb = 0.0f;
    TouristVehicle_ptr temp;//TouristVehicle* temp;
    for (TouristVehicle_ptr ptr : data)//t
    {
        if (ptr->perHrBookingCharge() > maxphb)
        {
            maxphb = ptr->perHrBookingCharge();
            temp = ptr;//
        }
    }
    return temp;
}

container FirstNTouristVeh(container &data, int n)
{
    if (data.empty())
        throw EmptyContainerException("Container is Empty\n");
    if (n > data.size() || n <= 0)
        throw OutOfBoundException("Value of N is not valid\n");
    container firstNVeh;
    for (TouristVehicle_ptr ptr : data)
    {
        if(n==0)
        return firstNVeh;
        firstNVeh.push_back(ptr);
        n--;
    }

    return firstNVeh;
}
