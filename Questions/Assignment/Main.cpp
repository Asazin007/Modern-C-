#include <iostream>

#include "TrainingBatch.h"
#include "Functionalities.h"

int main(){
Container c;
CreateObject(c);
std::cout<<c[0]->trainername()<<std::endl;
try
{
    /* code */
    DeleteObject(c);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
return 0;
}