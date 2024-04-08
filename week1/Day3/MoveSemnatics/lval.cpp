#include <iostream>
#include <list>

void Magic(std::list<int> & data){}

void WeidMagic(std::list<int>&& data){
    for(auto i:data){
        std::cout<<i<<" ";
    }
}

int main(){
    std:: list<int> l1{1,2,3,4,5};
    Magic(l1);
  
    WeidMagic(std::list<int> {1,2,4,5,6});
}