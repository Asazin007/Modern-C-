#include <iostream>
#include<functional>
/* 

the actual data type of lambda is unknown


 */

class Function_wrapper{
    private:
    // f<-------LAmbda  is store to this member
};

void Magic( std::function< void (int)> fn){
fn(10);
}

int main(){
    auto f1= [](int n){
        std::cout<<n*10;
    };
    f1(10);

    Magic([](int n)
          { std::cout << n * 10; }
          );

        return 0;
}