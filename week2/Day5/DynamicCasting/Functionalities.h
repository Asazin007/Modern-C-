#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Lion.h"
#include "Dog.h"
#include <memory>
#include<vector>

using AnimalPtr= std::shared_ptr<Animal>;
using Container =std::vector<AnimalPtr>;
using Dogptr=std::shared_ptr<Dog>;
using DogContainer =std::vector<Dogptr>;

void CreateObjects(Container& data);

DogContainer Dogscon(Container& data);

#endif
