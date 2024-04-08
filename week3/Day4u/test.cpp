#include <iostream>
#include <thread>
#include <variant>

int main(){
std::variant <int,std::string> v1;

// auto f1=[](){ std::cout<<"hello\n"; };
std::visit(
    [](auto&& val){
        std::cout<<val<<'\n';
    },
    v1
);

// t[0]=std::thread(f1);
// t[0].join();
}
/* 
Variant is can be empty and the first in order is displaye while printing in output stream
 */