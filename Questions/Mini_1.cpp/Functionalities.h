#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Device.h"
#include <optional>
#include <vector>
#include "EmptyContainerException.h"
#include "WrongValueException.h"

using Device_ptr=std::shared_ptr<Device>;
using container = std::vector<Device_ptr>;

void CreateObject(container &data);

std::optional<std::vector<float>> FindDiscountPrice(container &data);

int FindTaxAmount(container & data);

bool CheckLicensetype(container& data);


#endif // FUNCTIONALITIES_H
