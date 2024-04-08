#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Project.h"
#include <thread>
#include <condition_variable>

#include <vector>
#include <functional>
#include <mutex>

extern std::mutex mt;
extern std::condition_variable cv;

using Project_ptr= std::shared_ptr<Project>;
using ProjectContainer = std::vector<Project_ptr>;
using THreadContainer = std::vector<std::thread>;
using Fntype1 = std::function<void (ProjectContainer&)>;

using FnContainer = std::vector<Fntype1>;
using Fntype2 =std::function<void(FnContainer&)>;
using Fntype3 = std::function<void(FnContainer&,THreadContainer&,ProjectContainer&)>;
using Fntype4 = std::function<void (THreadContainer& data)>;
using Fntype = std::function<void(int&)>;

extern Fntype1 CreateObject;
extern Fntype2 Storefun;
extern Fntype3 Maptothreads;

extern Fntype1 IncreaseBudgetby2;
extern Fntype TakeInput;
extern Fntype1 DropOwnerlast;
extern Fntype1 Displayallprojects;
extern Fntype4 JoinThreads;
extern bool flag;

#endif // FUNCTIONALITIES_H
