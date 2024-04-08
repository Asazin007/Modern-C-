/*
objective:
-design a consumer for
- making allocation on the heap for 10 int.
-save sq. of all 10 in int on the heap.
-cal sum of first n  where n is accepted as user input as async
- Lauch a consumer Accepting N and passing to consumer


 */
#include <future>
#include <iostream>

int Consumer(std::future<int> &ft)
{
    int *ptr = (int *)malloc(40);
    auto f1 = [](int number)
    { return number * number; };

    for (int i=1; i <= 10; i++)
    {
        *(ptr + i - 1)= f1(i);
    }
    for (int i=1; i <= 10; i++)
    {
       std::cout<< *(ptr + i - 1)<<" ";
    }

    int n = ft.get();//wait+fetch;

    return (n*(n+1))/2;
}

int main()
{

    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<int> result = std::async(&Consumer, std::ref(ft));
    int val;
    std::cin>>val;
    pr.set_value(val);
    // result.wait();



    std::cout<<"\nThe ans is : "<<result.get()<<'\n';
}