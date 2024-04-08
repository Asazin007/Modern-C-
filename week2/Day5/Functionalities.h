#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<functional>
#include <vector>

using container= std::vector<int>;
using Fntype = std::function<void(container&)>;

void Adaptor(Fntype fn, container &data);

extern Fntype lfn1;
extern Fntype lfn2;
extern Fntype lfn3;

#endif // FUNCTIONALITIES_H
