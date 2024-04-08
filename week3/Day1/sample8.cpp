/* 

 */

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <array>

std::array<int ,15> result;
std::array<int ,5> number{1,2,3,4,5};
std::mutex mt;
int main(){
std::array<std::thread, 3> arr{
    std::thread(
        [&]()
        {  
            int n;
             for(int i=0;i<5;i++){
            n=number[i];
               
                result[i] = n * n;} }

        ),
        std::thread(
            [&]()
            { 
                int n;  for(int i=5;i<11;i++){
                    n=number[i-5];
               
                result[i] = n *n*n; }}

            ),
        std::thread(
            [&]()
            { int n;
                for(int i=10;i<15;i++){
                    n =number[i-10];
                    result[i]=1;
                   for(int j=1;j<=n;j++)
                    result[i] *= j; }}

        )
};
for(int i=0;i<3;i++){
    
    if (arr[i].joinable())
        arr[i].join();
}
for(auto i:result){
    std::cout<<i<<'\n';}
}