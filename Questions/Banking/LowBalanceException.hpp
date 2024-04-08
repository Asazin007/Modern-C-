#ifndef LOWBALANCEEXCEPTION_HPP
#define LOWBALANCEEXCEPTION_HPP

#include <stdexcept>
#include <cstring>
class LowBalanceException : public std::exception
{
    char *_msg;
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }

public:
    LowBalanceException() = delete;

    LowBalanceException(const LowBalanceException &) = delete; // disabled copy constructor

    LowBalanceException(LowBalanceException &&) = default; // disabled move constructor brand new in C++11

    LowBalanceException &operator=(const LowBalanceException &) = delete; // disabled assignment operator
    LowBalanceException &operator=(LowBalanceException &&) = delete;      // disabled assignment move operator brand new in C++11

    LowBalanceException(const char *msg)
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    ~LowBalanceException()
    {
        delete _msg;
    }

    
};

#endif // LOWBALANCEEXCEPTION_HPP
