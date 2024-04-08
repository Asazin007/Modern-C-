#include "Stack.hpp"
#include <iostream>

int main()
{
    Stack<int> s;
    try
    {
        /* code */
        s.Push(23);
        s.Pop();
        s.Pop();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}