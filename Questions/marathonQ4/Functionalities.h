#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <vector>
#include "Car.h"

/*
college student: Createobjects takes on vector of Car pointers to store objects of child types
 Professonal Engg. : 
 CreateObjects is a top level or a global function which takes one arg of type vector to Car pointer BY REF.
 this returns void.

*/
   // empty container

/*
USER---------------------------------------->CreateObjects
<-----------------------------------------------
    filled container

    main                                   createobj
    data
    [0X100h]





*/
void CreateObjects(std::vector<Car*>& data);
void DeleteObjets(std::vector<Car*>& data);

#endif // FUNCTIONALITIES_H
