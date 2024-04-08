#include <iostream>
// g++ -Werror -Wextra no_except.cpp
class Dummy
{
private:
    /* data */
public:
    Dummy(/* args */) noexcept{
        std::cout<<"noexcept"; //to ensure that there is no exception, programmer assumes that there is no exception,  if there is exception than it showa
        

    }
    ~Dummy() noexcept{}
};
int main(){

}