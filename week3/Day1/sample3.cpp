/* 

buferr : if you fixed a part of memory(RAM) for a specific task it is called buffer.
like wise, to print or show something on the the screen there is a buffer
 */
/*
it is syncronyous because afte one command finishes than other starts

we need to run parellelly
 */

#include <iostream>
#include <array>
#include <thread>
#include <functional>
#include <mutex>

std::mutex mt; // it is binary semaphore

void square(std::array<int, 5> &data)
{
    for (auto i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout << "\nSquare is: " << i * i;
        mt.unlock();
    }
}

void cube(std::array<int, 5> &data)
{
    for (auto i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        //only 1 executing entity should print on the screen
        mt.lock();
        std::cout << "\nCube is: " << i * i * i;
        mt.unlock();
    }
}

int main()
{
    // main thread starts cretes an array
    /*
    in local stack memory
    we launch new thread
    A thread is a mini program. As a devloper, t1 object is a "handle" for me to interact with the mini program square
    we passed data by ref
     */

    std::array<int, 5> data{1, 2, 3, 4, 5};
    std::thread t1(&square, std::ref(data));

    std::thread t2(&cube, std::ref(data)); // as well as t2

    t1.join(); // main will wait and join with the t1 thread
    t2.join();
    //     square(data);
    //     cube(data);
    // signal back , as a result / summary/ satisfaction
    std::cout << "\nGoodbye";
    // g++ sampl2.cpp -lpthread  -o ./app && time ./app
}
