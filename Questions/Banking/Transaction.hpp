#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include<iostream>
class Transaction{
private:
long int m_transaction{0};
public: 
    Transaction() = default;
    Transaction(const Transaction &) = delete; // disabled copy constructor
    Transaction(Transaction &&) = delete; // disabled move constructor brand new in C++11
    Transaction &operator=(const Transaction &) = delete; // disabled assignment operator
    Transaction &operator=(Transaction &&) = delete;	  // disabled assignment move operator brand new in C++11
    Transaction(long int transac);
    ~Transaction() = default;
    
    long int transaction() const { return m_transaction; }
    void setTransaction(long int transaction) { m_transaction = transaction; }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);
};

#endif // TRANSACTION_HPP
