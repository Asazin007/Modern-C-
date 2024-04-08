#include <iostream>
#include<functional>
#include <list>
#include<cstring>
/* 
bind 
1)we can not change the sequence of parameter
2)some parameter need to be fixed

 */

void Formula(const int x, const int y,const int z){
    std::cout<<"Answer is : "<<(x+y)-z<<"\n";
}

void Magic(const std::list<int>& data, int n){
    for(int val:data){
        n--;
        if(!n){
            std::cout<<val<<"\n";
        }
    }
}

int main(){
Formula(10,20,13);
auto binded_formula= std::bind(&Formula,100,std::placeholders::_1,std::placeholders::_2);

binded_formula(30,40);//x=100,y=30,40
// Magic(std::list<int> {1,3,4,5},3);
auto binded_magic = std::bind(&Magic,std::placeholders::_2,std::placeholders::_1);
binded_magic(3,std::list<int>{1, 3, 4, 5});
auto binded_strcpy = std::bind(strcpy, std::placeholders::_2, std::placeholders::_1);

char* msg=new char[8];
binded_strcpy("Asim", msg);
std::cout<<msg<<"\n";
auto fn =[](int n, int factor){
    std::cout<<n*factor<<" ";
};
//lambda is an object using & on a lamda means taking add of object. Dont use &

auto binded_lamda_fn = std::bind(fn, std::placeholders::_1, 40);


binded_lamda_fn(100);
binded_lamda_fn(100,20);//20 is discarded
binded_lamda_fn(100,20,30);//100,40 0nly 40 is fixed, other are discarded

//void Magic(const int n1, std::string& name);

//  std::function<void(const int,std::string&)>;
}