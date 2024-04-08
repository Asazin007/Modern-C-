#include <iostream>
#include <vector>
#include <functional>
/* 
n0, Identifier address content Alterate names
1      n1      0X99H     99      ref,argRef
 */

void sum(int n1,int n2,int n3){
    std::cout<<n1+n2+n3;
}
void Magic(const std::function<int(int)> fn,int &data){

    std::cout<<fn(data);
    // auto bind_fn=std::bind(&fn,100,std::plac);
    // bind_fn();

}

int main(){

    int n1=99;

    
    // std::vector<int&> values {n1};
    // int ref2= std::reference_wrapper<int>(n1);
    // int ref2ref=std::reference_wrapper<int>(ref2);
     
    // ref2ref++;

    int& a=std::reference_wrapper<int>(n1);


    
}
/* 

problems:
-a ref does not exits(it does not have seperate memory)
-ref of ref just create a ref of original val
solution:
A ref stored in a object internally creates representation of a reference callled reference wrapper

 */

