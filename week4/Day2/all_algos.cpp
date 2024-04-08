#include <algorithm>
#include <numeric>
#include <stdbool.h>
#include "Employee.h"
#include "Functionalities.h"

/*
1) `std::count_if`: This algorithm counts the number of elements in a range that satisfy a specific condition, which is defined by a unary predicate.

2) `std::find_if`: It searches for an element in a range that satisfies a specified condition, defined by a unary predicate. It returns an iterator to the first occurrence of such an element, or the end iterator if not found.

3) `std::any_of`: This algorithm checks if any element in a range satisfies a specified condition, again defined by a unary predicate. It returns true if at least one element satisfies the condition, otherwise false.

4) `std::all_of`: Similar to `std::any_of`, but it checks if all elements in a range satisfy the specified condition. It returns true if all elements satisfy the condition, otherwise false.

5) `std::none_of`: Opposite to `std::any_of`, this algorithm checks if none of the elements in a range satisfy the specified condition. It returns true if none of the elements satisfy the condition, otherwise false.

6) `std::copy`: Copies elements from a source range to a destination range. It accepts input iterators denoting the range to copy from and output iterator denoting the destination where elements are copied.

7) `std::copy_if`: Copies elements from a source range to a destination range, but only copies those elements that satisfy a specified condition, defined by a unary predicate.

8) `std::accumulate`: This algorithm calculates the sum of elements in a range or a custom accumulation operation can be specified. It starts with an initial value and iteratively combines it with each element in the range using a specified binary operation.

9) `std::max_element`: Finds the largest element in a range and returns an iterator to it. If multiple elements have the maximum value, it returns the iterator to the first occurrence of such an element.

10) `std::min_element`: Similar to `std::max_element`, but it finds the smallest element in a range and returns an iterator to it. If multiple elements have the minimum value, it returns the iterator to the first occurrence of such an element.

11)`std::distance calculates the number of elements between two iterators in a sequence. It takes two iterators as arguments and returns the number of elements between them.
 */

fntype countTrainer = [](EmployeeComtainer &data)
{
    std::cout << std::count_if(data.begin(), data.end(), [](const Employee &emp)
                               { return emp.designation() == "Trainer"; })
              << '\n';
};

auto findbyName = [](const EmployeeComtainer &data, std::string s)
{
    auto itr = std::find_if(data.begin(), data.end(), [&s](const Employee &emp)
                            { return emp.name() == s; });
    if (itr != data.end())
        std::cout << *(itr) << '\n';
    else
        std::cout << "Not found\n";
};
auto Anyofexp10yrs = [](const EmployeeComtainer &data)
{
    std::cout << std::boolalpha << std::any_of(data.begin(), data.end(), [](const Employee &emp)
                                               { return emp.expyrs() >= 10; })
              << '\n';
};

auto allofsalabove40 = [](const EmployeeComtainer &data)
{
    std::cout << std::all_of(data.begin(), data.end(), [](const Employee &emp)
                             { return emp.salary() > 40000.0f; })
              << '\n';
};

auto noneofsalabove40 = [](const EmployeeComtainer &data)
{
    std::cout << std::none_of(data.begin(), data.end(), [](const Employee &emp)
                              { return emp.salary() > 40000.0f; })
              << '\n';
};

auto copycontainer = [](const EmployeeComtainer &data1, EmployeeComtainer &data2)
{
    std::size_t count=0;
    auto itr = std::copy_if(data1.begin(), data1.end(), data2.begin(), [&](const Employee &emp)
                            {
       if(emp.salary()>50000) 
       { count++;
return true;}
return false; });
    data2.resize(count);
};

int main(int argc, char const *argv[])
{

    EmployeeComtainer data;
    CreateEmployee(data);
    countTrainer(data);
    findbyName(data, "Asim");
    Anyofexp10yrs(data);
    allofsalabove40(data);

    noneofsalabove40(data);
    EmployeeComtainer data2(data.size());
    copycontainer(data, data2);
    for(auto emp :data2)
    {
        std::cout<<emp<<'\n';
    }

    return 0;
}
