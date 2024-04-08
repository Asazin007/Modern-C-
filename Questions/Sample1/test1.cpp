#include<iostream>
class Car{
    public: 
    Car() = delete;
    Car(const Car &) = delete; // disabled copy constructor
    Car(Car &&) = delete; // disabled move constructor brand new in C++11
    Car &operator=(const Car &) = delete; // disabled assignment operator
    Car &operator=(Car &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Car() = default;
};
