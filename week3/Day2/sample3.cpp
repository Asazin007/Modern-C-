/* 
2 threads(2 workers)
    - main thread (producer): take input and "make available for consumtion"
    - operation (t1)[consumer] : once a singnal is recieved from main to indicate "input received ", calculate the square
        a) programmer calc how many workers are required and triggers them at a time[thread pooling!]
        b) t1 may want to do some other work even before data input is received
 */

#include <iostream>
#include <thread>
#include <condition_variable>
// #include <mutex>

std::mutex mt;
int value =0;
bool flag =false;
std::condition_variable cv;

void Operation(){
int* ans = (int*)malloc(4);

std::unique_lock<std::mutex> ul(mt);
cv.wait(ul, [&](){return flag;});

*ans = value *value;
std::cout<<"Square of "<<value<<" is : "<<*ans;
free(ans);
}
void takeinput(){
    std::lock_guard<std::mutex> lg(mt);
    std::cin >> value;
//production ready
   
}


int main(){
    std::thread t1(&Operation);
   takeinput();
   flag = true;
   //    send a sinal
   cv.notify_one();
   t1.join();
}
