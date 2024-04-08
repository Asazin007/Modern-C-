#include "Functionalities.h"

FunType CreateObject = [](Electic_Container &data1, DeiselContainer &data2,VtypeContainer& data)
{
    data1.push_back(std::make_shared<ElectricCar>(
        "Tesla C1",
        20000,
        1,
        400,
        100));

    data1.push_back(std::make_shared<ElectricCar>(
        "BMW i7",
        20456,
        2,
        4080,
        200));
    data2.push_back(std::make_shared<DeiselCar>(
        "BMW i7",
        20456,
        2,
        4080,
        200));

    data2.push_back(std::make_shared<DeiselCar>(
        "Audi R8",
        345.0f,
        600.0f,
        240.0f,
        100.0f));

    data2.push_back(std::make_shared<DeiselCar>(
        "Bugatti Veron",
        349,
        900,
        250,
        200));

    for (DeiselCar_ptr ptr : data2)
    {
        data.push_back(ptr);
    }
    for (Electic_ptr ptr : data1)
    {
        data.push_back(ptr);
    }


};



Fntype CommanAction = [](VtypeContainer &data)
{
    if(data.empty())
    throw EmptyDataException(std::future_errc::broken_promise,"Data is Empty\n");
    for (Vtype v : data)
    {
        std::visit(
            [](auto &&val)
            {
                std::cout << val->name() << " " << val->range() << " " << val->maxPower() << '\n';
            },
            v

        );
    }
};

// Fntype3 CommanAction2 = [](VVcontainer &data)
// {
//     for (Vtypevector v : data)
//     {
//         std::visit(
//             [](auto &&val)
//             {
//                 for (auto i : val)
//                     std::cout << i->name() << " " << i->range() << " " << i->maxPower() << '\n';
//             },
//             v

//         );
//     }
// };

Fntype UnCommanType = [](VtypeContainer &data)
{
    if (data.empty())
        throw EmptyDataException(std::future_errc::broken_promise, "Data is Empty\n");

    for (Vtype v : data)
    {
        if (std::holds_alternative<Electic_ptr>(v))
        {
            Electic_ptr ptr = std::get<0>(v);
            std::cout << '\n'
                      << "Battery Capacity : " << ptr->batteryCapacity();
        }
        else
        {
            DeiselCar_ptr ptr = std::get<1>(v);
            std::cout << '\n'
                      << "Fuel Capacity : " << ptr->fuelCapacity();
        }
    }
};

// Fntype3 UnCommanType2 = [](VVcontainer &data)
// {
//     for (Vtypevector v : data)
//     {
//         if (std::holds_alternative<Electic_Container>(v))
//         {

//             Electic_Container ptr = std::get<0>(v);
//             for (auto i : ptr)
//                 std::cout << '\n'
//                           << "Battery Capacity : " << i->batteryCapacity();
//         }
//         else
//         {
//             DeiselContainer ptr = std::get<1>(v);
//             for (auto i : ptr)
//                 std::cout << '\n'
//                           << "Fuel Capacity : " << i->fuelCapacity();
//         }
//     }
// };

Fntype highestMilege = [](VtypeContainer &data)
{
    if (data.empty())
        throw EmptyDataException(std::future_errc::broken_promise, "Data is Empty\n");

    float max = 0.0f;
    DeiselCar_ptr high;
    for (Vtype v : data)
    {
        if (std::holds_alternative<DeiselCar_ptr>(v))
        {
            DeiselCar_ptr ptr = std::get<1>(v);
            if (ptr->milage() > max)
            {
                max = ptr->milage();
                high = ptr;
            }
        }
    }

    std::cout << "Desel car with highest milage is: \n"
              << *high;
};

FunType2 StoreFunContainer = [](FnContanier &fdata)
{
    fdata.push_back(CommanAction);
    fdata.push_back(UnCommanType);
    fdata.push_back(highestMilege);
};

Fntype2 MaptoThread = [](FnContanier & fdata, ThreadContainer & tdata, VtypeContainer & data) {

        for(Fntype fn:fdata){
            tdata.push_back(std::thread(fn,std::ref(data)));
        }

        

};
std::function<void(FnContanier &, VtypeContainer &, AsyncContainer &)> AsyncCreater = [](FnContanier &fdata, VtypeContainer &data, AsyncContainer & adata)
{
    
    for (auto fn : fdata)
    {
        adata.push_back( std::async(fn, std::ref(data)));
    }
};

Fntype3 JoinThreads =[](ThreadContainer& tdata){

    for(std::thread &t: tdata){
        if(t.joinable()){
            t.join();
        }
    }
};


