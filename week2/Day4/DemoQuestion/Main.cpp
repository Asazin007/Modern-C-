#include "Functionalities.h"

int main(){
Container data;
ProContainer data2;

try
{
    CreateObj(data,data2);
    std::cout<<"Max Budget of the project : "<<MaxBudget(data);
    /* code */
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}


}