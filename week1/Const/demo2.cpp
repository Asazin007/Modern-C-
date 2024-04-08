#include <iostream>
#include <cstdio>
class dummy
{
private:
    int a{200};
public:
    dummy(/* args */)=default ;
    ~dummy()=default;
    void show(const dummy &d){
        printf("%d", d.a);
    }
                                                            
    };
    int main(){
        dummy d;
        const dummy d2;
        d.show(d2);
        
    }