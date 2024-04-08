#include "Functionalities.h"

int main()
{
    container data;
    try
    {
        CreateObject(data);
        std::cout << "Object is created\n";
        std::cout << "First N pointer \n";
        container firstNPointer = FirstNPointer(data, 2);
        for (TouristVehicle_ptr ptr : firstNPointer)
        {
            std::cout << *ptr;
        }
        std::cout<<"\nAverage of Per hour booking : "<<AvgPerhourBooking(data);
        TouristVehicle_ptr ptrmax= MaxPerhourBooking(data);
        std::cout<<"\nMax Tourist Vehicle with per hour booking: "<<*ptrmax;
        container firstNVeh = FirstNTouristVeh(data, 2);
        for (TouristVehicle_ptr ptr : firstNVeh)
        {
            std::cout <<"\n"<< *ptr;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}