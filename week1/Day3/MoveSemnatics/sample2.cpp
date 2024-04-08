#include <iostream>
#include <vector>
/**/
void arrcopy(int arr[]){
// arr[2]=-10000;
}
template <typename T>
std::vector<T> move(std::vector<T> &v)
{
    return v;
}

template <typename T>
T move(t &rval){
    return T;
}
void Magic(std:: vector<int> &&data){
std::cout<<data[3];
}
void Mag(int&&h){
    std::cout<<h;
}

int main(){
    std:: vector<int> v1{10,20,30,40,50};
    // Magic(std::vector<int> {1,2,3,4,5});
    // Magic(v1);
    // std::cout<<v1[2];
    Magic(move(v1));
    int a=100;
    Magic(move(a));

    int arr[]={1,2,3,4,5};
    arrcopy(arr);
    std::cout<<arr[2];
   
    

}