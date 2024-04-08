#include <iostream>
#include "Car.h"

#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IDnotfoundException.h"
int main(){
    Container c;
    CreateObjects(c);
    try{
    int ans = TotalHorsepower(c);
    std::cout<<"Total horsepower is: "<<ans<<"\n";
    float result = AverageTorque(c);
    std::cout << "Average torque is: " << result << "\n";
    std:: string model= FindCarModelById(c,"c102");
    std::cout << "Model for given ID is: " << model << "\n";
    bool flag = IsContainerAllCarAbove7lakhs(c);
    if(flag){
        std::cout << "All vehicles have price above 7 lakhs " <<  "\n";
    }
    else{
        std::cout << "All vehicles have price lower than 7 lakhs "
                  << "\n";
    }
    Engine* e= EnginePointerToMinPriceCar(c);
    std::cout << "Engine found: "<<*e
              << "\n";
              
    std::cout<<"Car Details:\n";
    DisplayData(c);          
    DeleteObjects(c);

}   
catch(const EmptyContainerException &e){
    std::cerr<<e.what()<<"\n";
}
catch(const IDnotfoundException &e){
    std::cerr<<e.what()<<"\n";
}
}