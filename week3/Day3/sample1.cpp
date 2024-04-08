/* 
Threads
    1) std::thread : They can be used for || or concurrent task. They need to be joined or detached.
    They do not catch the return value.

    2) std::condition_variable: In situations where one thread has to waith for an event to happen because of some other thread before completing its activity due to other operations, such threads may do some work before the event , hence are launched simultaneously.

    3)Container of std::threads : to manage multiple instances std::thread efficiently.(map to function and join, etc);

    4) std::mutex vs  std::lock_guard/ std::unique_lock
    -std::mutex can be locked and unlocked manually ONLY!
    -std::lock_guard : scope-based / RAII principle foolowing mutex. NO MANUAL/UNLOCK
    -std::unique_lock :Scope-based as well as manual lock/unlock.
//synchronization primitives

5) Real -life 
    -Mercedes : Navigation / MUSIC
    ---> unlock---> start the accessories / electronics
    I want to launch that performs task A and task B.
    We need to launch thread that wants a parameter enen without the parameter

 */
//std::future and std::async and std::promise
#include <future>
#include <iostream>

void Factorial(std::future<int>& ft){

    int *ptr =(int*)malloc(4); //this thread will block untill input

   int n=ft.get();
    int result =1;
    for(int i =2;i<n;i++){
        result*=i;
    }
    *ptr = result;
    std::cout<< "Final answer is: "<<*ptr<<'\n';

}
int main(){
//make a promise to compiler , i will give input in future 

std::promise<int> pr;//it set the val in producer
std::future<int> ft =pr.get_future();//it is used to read the val in consumer;

std::future<void> result = std::async(&Factorial, std::ref(ft));


int value=0;
std::cin>>value;

pr.set_value(value);
result.get();
// result.wait();

std::cout<<"goodbye";
}
 