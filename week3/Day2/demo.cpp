#include <iostream>

void add(int f) noexcept;
int main()
{
    bool f = false;
    while (!f)
    {
        add(5);
    }
}