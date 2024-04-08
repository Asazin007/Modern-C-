#include "Functionalities.h"

void CreateObjects(Container &data)
{
data.push_back(std::make_shared<Lion>(4,false,200));
data.push_back(std::make_shared<Dog>(4,true,100));
data.push_back(std::make_shared<Dog>(4,false,180));

}

DogContainer Dogscon(Container &data)
{
    DogContainer dogs;
    for(auto ptr:data){
        std::shared_ptr<Dog> d= std::dynamic_pointer_cast<Dog>(ptr);
        if(d){
            dogs.push_back(d);
        }
    }
    return dogs;
}
