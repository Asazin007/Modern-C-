#include "Functionalities.h"
std::mutex mt;
std::condition_variable cv;
bool flag = false;
Fntype1 CreateObject = [](ProjectContainer &data)
{
    data.push_back(
        std::make_shared<Project>("Battery Management System",
                                  2888891,
                                  "Ayush"));
    data.push_back(
        std::make_shared<Project>("Adas",
                                  2888891,
                                  "Asim"));
    data.push_back(
        std::make_shared<Project>("Ev",
                                  2888891,
                                  "Yuvraj"));
};

Fntype1 IncreaseBudgetby2 = [](ProjectContainer &data)
{
    for (Project_ptr ptr : data)
    {
        std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul, [&]()
                { return flag; });
            ptr->setBudget(ptr->budget() * 2);
    }
    // cv.notify_one();
};

Fntype1 DropOwnerlast = [](ProjectContainer &data)
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });
    data[data.size() - 1]->setAssinfnTo("NONE");
    // cv.notify_one();
};

Fntype1 Displayallprojects = [](ProjectContainer &data)
{
    for (Project_ptr ptr : data)
    {
       std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul, [&]()
                { return flag; });
        std::cout << *ptr << '\n';
    }
    // cv.notify_one();
};

Fntype2 Storefun = [](FnContainer &fdata)
{
    fdata.push_back(IncreaseBudgetby2);
    fdata.push_back(DropOwnerlast);
    fdata.push_back(Displayallprojects);
};

Fntype3 Maptothreads = [](FnContainer &fdata, THreadContainer &tdata, ProjectContainer &data)
{
    for (Fntype1 Fn : fdata)
    {
        tdata.push_back(std::thread(Fn, std::ref(data)));
    }
};

Fntype4 JoinThreads = [](THreadContainer &tdata)
{
    for (std::thread &t : tdata)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
};

Fntype TakeInput = [](int &val)
{
    std::cout << "Enter val";
    std::lock_guard<std::mutex> l(mt);
    std::cin >> val;
    std::cout << "val entered " << val;
};