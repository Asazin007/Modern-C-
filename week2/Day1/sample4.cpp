#include <iostream>

class LambdaImplementation
{
private:
    /* data */
    int _number;
public:
    LambdaImplementation(/* args */)= default;
    ~LambdaImplementation()= default;

    void operator()(int n){
            std::cout << "square of : " << n << "=" << n * n << "\n";
        
    }
};
//cppcon fun erasure
int main(){


    LambdaImplementation l1;
    l1(20);
}