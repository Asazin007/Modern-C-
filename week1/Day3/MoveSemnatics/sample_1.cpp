#include <iostream>
#include <vector>
/*
numbers passed to magic always temporary values
*/
void Magic(std:: vector <int>&& data){
    
    std::cout<<data[4];

}


int main(){
std::vector <int> value{10,20,30,40,50};
Magic(std::move(value));

// std::cout<<value[2]<<"\n";
}



/*
1) Prog starts coz os shedules

2)Mian function is executed as a thread by os
3) vectors of int val is created in the scope of main 
  - heap allocation happens and vector gets space on heap
  - pointers to start , end and capacity are recorded in the vector object "value" in the main 
4) Magic(move)
  - std::move(value): it converts lvalue into rvalues(tells the compiler value is prepared to move) 
  -  Now vec value is treated as rvalue....

*/