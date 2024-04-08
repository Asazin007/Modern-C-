/* 
createive a adapter which takes 
1)A callable of the fllowing signature 
Input: int and int output void
2)integer number n1
3)integer number n2
THe adapter must appy the calllble on the 2) and 3) integers
 */

/* 
Adaptor is a higher order funtion that accepts a 
a)a function wrapper for all the funtions that have the fllowing signature
1)int,int input parameters
ii) void as a return type 
 */
#include <iostream>
#include <functional>

void Adapter( std::function<int(int,int)> fn, int n1,int n2){
   std::cout<< fn(n1,n2);
}
int f1(int n1, int n2){
    return n1+n2;
}
int main(){
  
  Adapter([](int n1, int n2){
    return n1+n2;
  },10,20);
  Adapter(f1,20,40);

}
