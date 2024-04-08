#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "ElectricCar.h"
#include "DeiselCar.h"
#include <functional>
#include <variant>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include <future>
#include "EmptyDataException.h"


using Electic_ptr= std::shared_ptr<ElectricCar>;
using Electic_Container = std::vector<Electic_ptr>;

using DeiselCar_ptr = std::shared_ptr<DeiselCar>;
using DeiselContainer = std::vector<DeiselCar_ptr>;
using Vtype = std::variant<Electic_ptr,DeiselCar_ptr>;


// using Vtypevector =std::variant <Electic_Container,DeiselContainer>;
// using VVcontainer = std::vector<Vtypevector>;


using VtypeContainer= std::vector<Vtype>;
using FunType = std::function<void (Electic_Container&,DeiselContainer&,VtypeContainer&)>;
using Fntype = std::function<void (VtypeContainer &)>;


// using Fntype2 = std::function<DeiselCar_ptr (VtypeContainer &)>;

using FnContanier = std::vector<Fntype>;
// using Fntype3 = std::function<void(VVcontainer &)>;
using FunType2 = std::function<void(FnContanier &)>;

using AsyncContainer = std::vector<std::future<void>>;

using ThreadContainer = std::vector<std::thread>;

using Fntype2 = std::function<void(FnContanier &, ThreadContainer& ,VtypeContainer& )>;
using Fntype3 = std::function < void(ThreadContainer&)>;


//--------------------------------------------------------------------------

extern FunType CreateObject;

extern FunType2 StoreFunContainer;

extern std::function<void(FnContanier &, VtypeContainer &,AsyncContainer&)> AsyncCreater;

extern Fntype CommanAction;
// extern Fntype3 CommanAction2;

extern Fntype UnCommanType;
// extern Fntype3 UnCommanType2;

extern Fntype highestMilege;

extern std::function<int(Electic_Container&)> batteryCap;
extern Fntype2 MaptoThread;

extern Fntype3 JoinThreads;



#endif // FUNCTIONALITIES_H
