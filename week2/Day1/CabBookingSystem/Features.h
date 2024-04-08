#ifndef FEATURES_H
#define FEATURES_H
#include <memory>
#include <vector>
#include "Account.h"
using AccountContainer= std::vector<std::shared_ptr<Account>>;

/* 
should accept ref of a container
an enum to decide type of account
then accept input  and call the constructer and pointer in account container

 */
#include<iostream>
class Features{
private:

public: 
    Features() = delete;
    Features(const Features &) = delete; // disabled copy constructor
    Features(Features &&) = delete; // disabled move constructor brand new in C++11
    Features &operator=(const Features &) = delete; // disabled assignment operator
    Features &operator=(Features &&) = delete;	  // disabled assignment move operator brand new in C++11
    ~Features() = default;
    static CreateObject(AccountContainer& account, AccountType acctype);

};

#endif // FEATURES_H
