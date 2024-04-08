#include <iostream>
void magic(int value){
    std::cout<< "value in Magic b4 modificatoion is: "<< value<<"\n";
    std::cout<<"address of value pf inside :s : "<<&value<<"\n";
    value = 111;
    std:: cout<< "value in Magic after modification is: "<<value<<"\n";
}
int main(){
    int val = 100;
    std::cout<<"value in main b4 modification is :"<<val<<"\n";
    std::cout<<"address in main b4 modification is :"<<&val<<"\n";
    magic(val);
    std:: cout<<"value in main after modification is :"<<val <<"\n";
}