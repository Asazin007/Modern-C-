#include "Employee.h"


//inline function, overload

template<typename T, typename... Args>
T Relay(Args&&... args){
    return T(std::forward<Args>(args)...);
} 


void magic(int &&n1){
    std::cout<<n1;
}

int main(){
   Employee emp = Relay<Employee>("Asim",600000.0f,"Trainee",23);
   std::cout<<emp<<'\n';
   magic(Relay<int>(23));

}