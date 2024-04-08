#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "TrainingBatch.h"
#include <memory>
using BatchPointer = std::shared_ptr<TrainingBatch>;
using Container = std::vector<TrainingBatch *>;
void CreateObject(Container &data);

void DeleteObject(Container &data);

#endif // FUNCTIONALITIES_H
