/*

 */
#include <vector>
#include <functional> //support for functional programmiing
#include <iostream>
void Cube(int n)
{
    std::cout << "cube of : " << n << "=" << n * n * n;
}

// operartion is  a higher order fun
// it accepts or returns (or both) another fun
//  void operaton(int *arr, int size, void(*ptr)(int))
//  {
//      for (int i = 0; i < size; i++)
//      {
//          (*ptr)(arr[i]);
//      }}
void operaton(const std::vector<int> &data, std::function<void(int)> fn)
{
    for (int val : data)
    {
        fn(val);
    }
}

int main()
{
    // void (*ptr)(int) = square;
    // void (*ptr2)(int) = Cube;
    auto temp = [](int n) -> void
    {
        std::cout << "square of : " << n << "=" << n * n << "\n";
    };
    std::vector<int>
        v = {10, 20, 30, 40, 50};
    operaton(
        v,
        [](int n)                                                             
        {
            std::cout << "square of : " << n << "=" << n * n << "\n";
        }); // lamda function
}

/*
Higher order functions
Ananomous functon
function programming
 */