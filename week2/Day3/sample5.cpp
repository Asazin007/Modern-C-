/* 
triggers app
f1----> f2(2 integers will be created )
|   |   |   |
|   |   |   |
|   |   |   | pedicate to filter the data
 */

#include <iostream>
#include <functional>

// void f2(int n1, int n2){
//     /* 
//     A lambda can capture data from its enclosing fn without explicit passing 
//     &-> capture by ref, any chage will reflect in f2
//     =-> capture by =, it will copy the data in fn
//      */
//     auto lamda_fn =[& ](){
//         return n1+n2;
//     };
//     lamda_fn();
// }

std::function<int()> f2(int n1, int n2)
{
    /*
    A lambda can capture data from its enclosing fn without explicit passing
    &-> capture by ref, any chage will reflect in f2
    =-> capture by =, it will copy the data in fn
     */
    auto lamda_fn = [&]()
    {
        int val=99;
        return n1 + n2+99;
    };
    // lamda_fn();
    return lamda_fn;
}
void f1(){
    int n1=10;
    int n2=20;
    std::function<int()> mod_fn= f2(n1, n2);

    std::cout<<mod_fn()<<"\n";
}
int main(){

    f1();
}

/*
void Magic(){
    int n1=10, n2=20;
    ex1: all data values from "enclosing function"(Magic) are eccessible inside f1
    auto f1= [&](){
        return n1+n2;
    }
}

ex:bselected data valuses  capture by
void Magic(){
    int n1=10, n2=20;

    auto f1= [n1](){
        return n1+n2;
    }
}
ex3: both by copy
void Magic(){
    int n1=10, n2=20;

    auto f1= [n1,n2](){
        return n1+n2;
    }
}
ex:both by ref
void Magic(){
    int n1=10, n2=20;

    auto f1= [&n1,&n2](){
        return n1+n2;
    }
}
ex4: all data by valus/copy
void Magic(){
    int n1=10, n2=20;

    auto f1= [=](){
        return n1+n2;
    }
}
ex:some by val some by ref
void Magic(){
    int n1=10, n2=20;

    auto f1= [n1,&n2,&n3](){
        return n1+n2;
    }
}

 */


void trick(){
    int n1= 100;
    auto f1=[=]()mutable{
        n1=99;  //without mutable it will give error;
    };
}




