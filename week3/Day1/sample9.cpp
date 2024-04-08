#include <array>
#include <functional>
#include <thread>
#include <iostream>

using FnTpye = std::function<void(int)>;
using FnContainer = std::array<FnTpye, 3>;
using InputContainer = std::array<int, 5>;
using ResultContainer = std::array<int, 15>;
using ThreadArray = std::array<std::thread, 3>;

void StoreFuntionContainer(FnContainer &fns, InputContainer &data, ResultContainer &result)
{
    fns[0] = [&](int k)
    {
        for (int number : data)
        {
            result[k++] = number * number;
        }
    };

    fns[1] = [&](int k)
    {
        for (int number : data)
        {
            result[k++] = number * number * number;
        }
    };

    fns[2] = [&](int k)
    {
        for (int number : data)
        {
            result[k++]=1;
            for(int i =1;i<=number;i++)

                result[k-1] *= i;
        }
    };
}

void JoinThreads(ThreadArray &thArr)
{
    for (std::thread &t : thArr)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}

void MapFunctionThread(FnContainer &fns, ThreadArray &thArr)
{
    int pos[] = {0, 5, 10};
    for (int i = 0; i < 3; i++)
    {
        thArr[i] = std::thread(fns[i], pos[i]);
    }
}

void Display(ResultContainer &result)
{
    for (int i : result)
    {
        std::cout << i << "\n";
    }
}

int main()
{
    InputContainer data{1, 2, 3, 4, 5};

    ResultContainer result;

    ThreadArray thArr;

    FnContainer fns;

    StoreFuntionContainer(fns, data, result);

    MapFunctionThread(fns, thArr);

    JoinThreads(thArr);

    Display(result);
}
