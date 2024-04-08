#ifndef NOTRANSACTIONEXCEPTION_HPP
#define NOTRANSACTIONEXCEPTION_HPP

#include <stdexcept>
#include <cstring>
class NoTransactionException : public std::exception
{
    char *_msg;
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }

public:
    NoTransactionException() = delete;

    NoTransactionException(const NoTransactionException &) = delete; // disabled copy constructor

    NoTransactionException(NoTransactionException &&) = default; // disabled move constructor brand new in C++11

    NoTransactionException &operator=(const NoTransactionException &) = delete; // disabled assignment operator
    NoTransactionException &operator=(NoTransactionException &&) = delete;      // disabled assignment move operator brand new in C++11

    NoTransactionException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~NoTransactionException()
    {
        delete _msg;
    }

    
};

#endif // NOTRANSACTIONEXCEPTION_HPP
