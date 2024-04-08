/*
variadic templates
 */

#include <iostream>
/*

+ opertor is overloaded for addintion */
template <typename T>
int add(T n1)
{
    return n1;
}

template <typename T, typename... Remaining>
T add(T n1, Remaining... args)
{

    return n1 + add(args...);
}
template <typename T>
void print(T n1)
{
    std::cout << n1;
}

template <typename T, typename... Rem>
void print(T n1, Rem... args)
{
    print(n1);
    print(args...);
}


// void print(std::string n1)
// {
//     std::cout << n1;
// }

// template <typename T, typename... Rem>
// void print(std::string n1, Rem... args)
// {
//     // std::cout << n1;
//     print(n1)
//     print(args...);
// }

int main()
{

    std::cout << add<int>(10, 20) << '\n';
    add<float>(12.0f, 102.f); // meta prom=gamming , compiler writing code for you
    print("gourav",68484, "chutiya hai",234,59903, 4384,5577 );
}

/*


 */