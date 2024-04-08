/* 
set works same as hash table,
but its key and value are same

 */

#include <iostream>
#include <unordered_set>

int main(){
    std::unordered_set<int> s1 {11,22,23,11,23,4,6,7,9,11};
    auto pair = s1.insert(11);

    if(pair.second){
        std::cout<<"Element added\n";
    }
    else{
        std::cout<<"Element not added\n";

    }
    for( int i:s1){
        std::cout<<i<<" ";
    }
}