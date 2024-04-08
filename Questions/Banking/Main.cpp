#include "Functionalities.hpp"
// #include "Accounts.hpp"
#include <iostream>
#include <memory>

int main()
{
    bool bug=true;
    while(bug){ 
    try
    {
        CreateAccount();
        Withdraw();
        RollBack();
        bug =false;
                                                   
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    }
   
}