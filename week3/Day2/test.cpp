#include <iostream>
#include<thread>
#include <mutex>
std::mutex mt;
void widthdraw(int &amount){
    std::lock_guard<std::mutex> lg(mt);
    for(int i=0;i<100;i++){
        amount-=100;
    }
}
void credit(int &amount)
{
    std::lock_guard<std::mutex> lg(mt);
    for (int i = 0; i < 100; i++)
    {
        amount += 100;
    }
}

int main(){
    int amount=10000;
    std::thread t1(&widthdraw,std::ref(amount));
    std::thread t2(&credit, std::ref(amount));
    t1.join();
    t2.join();
    std::cout<<amount;
    return 0;
}