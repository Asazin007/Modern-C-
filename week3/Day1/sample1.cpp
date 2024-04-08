/* 

processor: it is a hardware device baes on silicon  
which executes instructuction given 
ex=Intel i5 12 gen 12

core : this is the section of the processor which is cable of executing one whole process

[  c1   |  c2   ]
[   c3  |  c4   ]

single thread, single process, syncronous program.(this type of code we have written)

delays: IO delay, CPU bound Delay

 */

#include <iostream>
#include <array>
#include <thread>

void square(std::array<int, 5> & data){
    for(auto i: data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nSquare is: " << i*i;
    }
}

void cube(std::array<int, 5> &data)
{
    for (auto i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nCube is: " << i * i*i;
    }
}

int main(){

    std::array<int,5> data {1,2,3,4,5};
    square(data);
    cube(data);
}
