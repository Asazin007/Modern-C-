#include "Functionalities.h"

int main(){

Electic_Container data1;
DeiselContainer data2;
VtypeContainer data;
FnContanier fdata;
AsyncContainer adata;
ThreadContainer tdata;

 
 try
 {
    /* code */

    CreateObject(data1,data2,data);
    StoreFunContainer(fdata);
    
   //  JoinThreads(tdata);
   AsyncCreater(fdata, data, adata);
    // VVcontainer datav {data1, data2};
//    for (auto &i : adata){
// i.get();
//    }
 }
 catch(const std::future_error& e)
 {
   
    std::cerr << e.what()<< '\n';
 }
 


}