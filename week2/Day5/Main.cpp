#include "Functionalities.h"

int main()
{
    container v = {3,
                   4,
                   5,
                   6,
                   7,
                   8};
    try
    {

        Adaptor(lfn1, v);

        Adaptor(lfn2, v);

        Adaptor(lfn3, v);

        Adaptor([](container& data){
            std::cout<<data.front()+data.back();
        },v);
        /* code */
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}