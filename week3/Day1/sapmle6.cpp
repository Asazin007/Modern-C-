/*
RAII
ine object of this class will be responsible for one connection mechanism to bank

 */
#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <memory>


class BankingOperation
{
private:
    /* data */
    int _amount{0};
    std::mutex mt;
    BankingOperation(int amount) : _amount{amount}
    {
    }
    static BankingOperation* _solo_obj;
public:
    
    BankingOperation(const BankingOperation &) = delete;
    BankingOperation(BankingOperation &&) = delete;
    BankingOperation operator=(const BankingOperation &) = delete;
    BankingOperation operator=(BankingOperation &&) = delete;
    ~BankingOperation() = default;

    void Withdraw()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int i = 0; i < 100; i++)
        {

            std::lock_guard<std::mutex> lk(mt); // RAII principle
            _amount -= 10;
        }
    }
    void Deposit()
    {

        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int i = 0; i < 100; i++)
        {
            std::lock_guard<std::mutex> lk(mt);
            _amount += 10;
        }
    }

    int amount() const { return _amount; }

    static BankingOperation* getfirstobj(int amount){
        if(_solo_obj)
        return _solo_obj;

        else
        {
            _solo_obj = new BankingOperation(amount);
            return _solo_obj;
        }
    }
};
BankingOperation* BankingOperation::_solo_obj{nullptr};

int main()
{
    BankingOperation* b1=BankingOperation::getfirstobj(1000); // value initialization
    std::thread arr[2] = {
        std::thread(&BankingOperation::Withdraw, b1),
        std::thread(&BankingOperation::Deposit, b1)};

    for (int i = 0; i < 2; i++)
    {
        if (arr[i].joinable())
            arr[i].join();
    }
    std::cout << "Amount left: " << b1->amount();
    
}