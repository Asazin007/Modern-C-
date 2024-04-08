#include <iostream>
#include <string>

template <typename... T>
auto add(T... n1){
    return (n1+ ...); //right associative operation 
    /* 
    (30+(40+50))
     */
}
template <typename... A>
auto Subtract(A... arg){
    return (... - arg);//left associative operation
    /* 
    (((10-20)-50)-40)
     */
}



int main(){

    std::cout<<add(20,30,50,30,60)<<'\n';
    std::cout<<Subtract(40,30,40);
  
}

/* 

std::thread
    -onr thread
    -array of threads
    -std::mutex for race condition
    - std:: loc_guard to manage mutex based on scope
if initializer

std::optional

structure binding

std::variants
    -functional pol
    -std::visit, std::hold_alternative
std::condition_variable
    -uniquelock, notify mechanism

std::async
    -with future_input
    -without future input

variadic temp

fold templates


 */