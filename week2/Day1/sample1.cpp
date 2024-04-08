/* 

 */
#include <functional>//support for functional programmiing
#include<iostream>
void square(int n){
    std::cout<<"square of : "<<n<<"="<<n*n;
}
void Cube(int n)
{
    std::cout << "cube of : " << n << "=" << n * n*n;
}

//operartion is  a higher order fun
//it accepts or returns (or both) another fun
// void operaton(int *arr, int size, void(*ptr)(int))
// {
//     for (int i = 0; i < size; i++)
//     {
//         (*ptr)(arr[i]);
//     }}
    void operaton(int *arr, int size, std::function<void(int)> fn)
    {
        for (int i = 0; i < size; i++)
        {
            fn(arr[i]);
        }
    }

    int main()
    {
        // void (*ptr)(int) = square;
        // void (*ptr2)(int) = Cube;
        int arr[5] = {10, 20, 30, 40, 50};
        operaton(arr, 5, Cube);
    }

    /*
    Higher order functions
    Ananomous functon
    function programming
     */