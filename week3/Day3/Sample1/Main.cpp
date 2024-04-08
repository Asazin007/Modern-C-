#include <iostream>
#include "Functionalities.hpp"
#include <future>
#include <functional>
#include <thread>

int main()
{

    Container c;
    Container b;
     std::thread t1(createObjects,std::ref(c));
     t1.join();

    try
    {
        std::future<int> ans =std::async( TotalHorsePower, std::ref(b));
        int lol = ans.get();
        std::cout << "Total horsepower is: " << lol << "\n";
        std::future <float> ans2 = std::async(AverageEngineTorque, std::ref(c));
        std::cout << "Average Torque is: " << ans2.get() << "\n";
        std::future <std::string> ans3 = std::async(FindCarModelById, std::ref(c) ,"c101");
        std::cout << "Model for given id is: " << ans3.get() << "\n";
        std::future <bool> flag = std::async(isContainerAllCarAbove700000, std::ref(c));
        if (flag.get())
        {
            std::cout << "All cars have price are above 7lakhs\n";
        }
        else
            std::cout << "Some cars have price less than or equal to 7lakhs\n";

        std::future <Engine *> e = std::async(EnginePointerToMinPriceCar, std::ref(c));
        std::cout << "Engine details are: " << *(e.get());

        deleteObjects(c);
    }
    catch (const std::future_error &e)
    {
        std::cerr << e.what() << '\n';
        if (e.code() == std::future_errc::no_state)
        {
            std::cerr << "Data nhi hai\n";
        }

        

       
    }

    return 0;
}