#include <iostream>
#include <functional>

class Action
{
private:
    /* data */
    int _id{9};

public:
    Action() = default;
    ~Action() = default;

    void Operation(int n){ std::cout<<_id*n;}
    void operator()(int n){
        std::cout<<n*4<<"\n";
    }
};

int main(){
    Action a1;
    auto binded_operation = std::bind(&Action::Operation,a1,40);//it is mandatory to use & before Operation, its a non static function of a classs
    binded_operation();
    auto binded_over = std::bind(Action(),80);
    binded_over();

}