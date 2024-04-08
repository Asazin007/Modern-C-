#include "Functionalities.h"

int main(){

int k;
ProjectContainer data;
THreadContainer tdata;
FnContainer fdata;

std::thread t1(CreateObject,std::ref(data));
t1.join();

std::thread t2(Storefun, std::ref(fdata));
t2.join();

std::thread t3(Maptothreads ,std::ref(fdata), std::ref(tdata),std::ref(data));
t3.join();
// Maptothreads(fdata,tdata,data);


TakeInput(k);
std::this_thread::sleep_for(std::chrono::seconds(2));
flag =true;
cv.notify_all();

JoinThreads(tdata);
// std::thread t4(JoinThreads,std::ref(tdata));
// t4.join();
}