#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
class Account{
private:
unsigned long int m_id;
std::string m_username;
static long int m_counter;

public: 
    Account() = delete;
    Account(const Account &) = delete; // disabled copy constructor
    Account(Account &&) = delete; // disabled move constructor brand new in C++11
    Account &operator=(const Account &) = delete; // disabled assignment operator
    Account &operator=(Account &&) = delete;	  // disabled assignment move operator brand new in C++11
    explicit Account(const std::string username );
    virtual void RegisterAccount()=0;
    ~Account() = default;

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    std::string username() const { return m_username; }
    void setUsername(const std::string &username) { m_username = username; }

    static int counter() { return Account::m_counter; }
    static void setCounter(int counter) { Account::m_counter = counter; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    
};

#endif // ACCOUNT_H
