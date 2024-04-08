#include "Funtionalities.h"

std::mutex mt; // Define the mutex

Fntype1 CreateObject = [](EmployeeContainer &data)
{
    data.push_back(
        std::make_shared<Employee>(
            "Asim",
            60000,
            "Trainee"

            ));

    data.push_back(
        std::make_shared<Employee>(
            "Gourav",
            61000,
            "Trainee"

            ));
    data.push_back(
        std::make_shared<Employee>(
            "Harshit",
            60000,
            "Trainer"

            ));
    data.push_back(
        std::make_shared<Employee>(
            "Ayush",
            65000,
            "Trainee"

            ));
};

Fntype2 IsallsalAbove40k = [](EmployeeContainer &data)
{
    return std::all_of(data.begin(), data.end(), [](Employee_ptr &e)
                       { return e->salary() > 40000; });
};

Fntype3 MaxSalary = [](EmployeeContainer &data)
{
    auto ele = std::max_element(data.begin(), data.end(),
                                [](Employee_ptr e1, Employee_ptr e2)
                                {
                                    return e1->salary() < e2->salary();
                                });
    Employee_ptr ptr = *ele;
    return ptr->salary();
};

Fntype4 FindDetails = [](EmployeeContainer &data, std::future<std::string> &name)
{
    std::string n = name.get();
    auto itr = std::find_if(data.begin(), data.end(),
                            [&n](Employee_ptr &e)
                            {
                                return e->name() == n;
                            });
    return *itr;
};

Fntype5 FindWithdesig = [](EmployeeContainer &data, std::future<std::string> &des)
{
    std::string d = des.get();
    int c = std::count_if(data.begin(), data.end(), [&d](Employee_ptr &emp)
                          { return emp->designation() == d; });
   std::this_thread::sleep_for(std::chrono::seconds(2));
    std::lock_guard<std::mutex> l(mt);
    std::cout << "\nCount of employee with designation " << d << " : " << c << '\n';
};
