/* 
week 2 :
Function pointer 
Function wrapper
    -a way to capture any callable in a type-erased way
    -It can be used for followiing
        -Pass a callable as a parameter
        -Return a callable as a value
        -save functional as "values" in container/variable
Reference Wrapper
    - It is an object that internally stores ref to "something"
    - it uses a pointer
    - It can br replcement for raw ref everywhere in the code;
    - Rvalue cannot be converted to reference wrapper.

std::bind
    -used to create a partial fuction
    - a function some 

 */
#include<iostream>
#include<functional>
#include <vector>

void Adaptor(std::vector<std::function<void(int)>> &v,std::vector<int>& v2){
for(int i =0;i<3;i++){
for(int j=0;j<v2.size();j++){
    v[i](v2[j]);
}
std::cout<<"\n";
}
}

int main(){
    
    
    
    std::vector<std::function<void(int)>> v{
        [](int n)
        {
            std::cout<<"Value: "<<n<<"\n";
        },
            [](int j)
        {
            std::cout <<"Square: "<< j*j << "\n";
        },
            [](int k)
        {
            std::cout<<"Cube: " << k*k*k << "\n";
        }
    };

    std::vector<int> v2{23,45,67};
    Adaptor(v,v2);
}



/* 
class A

std::vector<A> v;

 */