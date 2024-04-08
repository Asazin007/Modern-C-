#include "Functionalities.h"

void Adaptor(Fntype fn, container &data)
{
    if (data.empty())
        throw std::runtime_error("Data is empty\n");

    fn(data);
}

Fntype lfn1 = [](container &data)
{
    std::cout << data.front() << '\n';
};


Fntype lfn2 = [](container &data)
{
    std::cout << data.back() << '\n';
};

Fntype lfn3 = [](container &data)
{
    std::cout << data.size() << '\n';
};