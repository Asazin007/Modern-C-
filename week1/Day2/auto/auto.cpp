#include <iostream>
#include <vector>
/*
use inly for innitializaton
for each
return type
lambda variable name
function parameter with auto
templete parameters for lambda[c++ 14]

auto&& in for loop

---dont use auto when you have no idea hwat to use

---always verify whether auto can be use where you are using it
*/
int main(){
    auto n1=10;
    std::vector<int> v1{1,2,3,4};
    auto itr = v1.begin();
    decltype(v1) v2={2,3,4,5,6,7};
}