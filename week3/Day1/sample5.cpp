#include <iostream>
#include <thread>
#include <functional>
#include <mutex>

std::mutex mt;
void Withdraw(int &amount)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 100; i++)
    {

        std::lock_guard<std::mutex> lk(mt); //RAII principle
        amount -= 10;
       
    }
}
void Deposit(int &amount)
{

    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 100; i++)
    {
        std::lock_guard<std::mutex> lk(mt);
        amount += 10;
        
    }
}

int main()
{
    int amount = 1000;
    std::thread t1(&Withdraw, std::ref(amount));
    std::thread t2(&Deposit, std::ref(amount));

    t1.join();
    t2.join();
    std::cout << "\nAmount left: " << amount;
}
