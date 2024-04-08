#include "copy_elison_Employee.h"

Employee Magic(){
    Employee e1("Harshit", 70000.0f, "Trainer", 10);
    std::cout<<&e1<<'\n';
    return e1;
}
int move(int a){
    return a;
}

int main(){
    Employee emp =Magic();
    std::cout<<&emp<<"\n";
    int a=45;
    int &&b= move(a);
    std::cout<<a;

}