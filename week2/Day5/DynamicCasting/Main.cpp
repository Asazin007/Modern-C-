#include "Functionalities.h"

int main(){
    Container data;
    try
    {
        
        CreateObjects(data) ;
        
        DogContainer  dogs = Dogscon(data);
        for (auto d : dogs){
            d->who();
            d->vioce();
            std::cout<<d->speed()<<'\n';
            
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}