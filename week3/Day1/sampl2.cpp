/* 
it is syncronyous because afte one command finishes than other starts

we need to run parellelly
 */


#include <iostream>
#include <array>
#include <thread>
#include <functional>

void square(std::array<int, 5> &data)
{
    for (auto i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nSquare is: " << i * i;
    }
}

void cube(std::array<int, 5> &data)
{
    for (auto i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nCube is: " << i * i * i;
    }
}

int main()
{
    //main thread starts cretes an array 
    /* 
    in local stack memory
    we launch new thread
    A thread is a mini program. As a devloper, t1 object is a "handle" for me to interact with the mini program square
    we passed data by ref 
     */

    std::array<int, 5> data{1, 2, 3, 4, 5};
    std::thread t1(&square,std::ref(data));

    std::thread t2(&cube, std::ref(data));//as well as t2

    t1.join();//main will wait and join with the t1 thread
    t2.join();
//     square(data);
//     cube(data);
    // signal back , as a result / summary/ satisfaction
    std::cout<<"Goodbye";
    // g++ sampl2.cpp -lpthread  -o ./app && time ./app
}
