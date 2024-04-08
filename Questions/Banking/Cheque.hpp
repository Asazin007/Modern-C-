#ifndef CHEQUE_HPP
#define CHEQUE_HPP

#include<iostream>
class Cheque{
private:

public: 
    Cheque() = delete;
    Cheque(const Cheque &) = delete; // disabled copy constructor
    Cheque(Cheque &&) = delete; // disabled move constructor brand new in C++11
    Cheque &operator=(const Cheque &) = delete; // disabled assignment operator
    Cheque &operator=(Cheque &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Cheque() = default;
};

#endif // CHEQUE_HPP
