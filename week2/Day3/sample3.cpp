/* 
Objectio=ve :Design an adapter to accept 
a vector of int 
a  predictive ( a fun return true or false based on single input)
 use the predictive(return t or f based on input) to print a data from the vector
 */
#include <functional>
#include <vector>
#include <iostream>

void Adaptor(std::function<bool(int)> predicate,const std::vector<int>& data ){
    for(int val: data){
        if(predicate(val)){
            std::cout<<val<<" ";
        }
    }
}


int main(){

std::vector<int> v={10,12,13,14,15,20};
    Adaptor([](int n){
return n%5==0;
    }, v);

    Adaptor([](int n)
            { return n % 5 == 0&& n%3==0; },
            std::vector<int>{23,45,12,34,44});
}