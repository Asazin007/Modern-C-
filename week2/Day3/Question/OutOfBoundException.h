#ifndef OUTOFBOUNDEXCEPTION_H
#define OUTOFBOUNDEXCEPTION_H

#include <stdexcept>
#include <cstring>
class OutOfBoundException : public std::exception
{
    char *_msg;
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }

public:
    OutOfBoundException() = delete;

    OutOfBoundException(const OutOfBoundException &) = delete; // disabled copy constructor

    OutOfBoundException(OutOfBoundException &&) = default; // disabled move constructor brand new in C++11

    OutOfBoundException &operator=(const OutOfBoundException &) = delete; // disabled assignment operator
    OutOfBoundException &operator=(OutOfBoundException &&) = delete;      // disabled assignment move operator brand new in C++11

    OutOfBoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~OutOfBoundException()
    {
        delete _msg;
    }

    
};

#endif // OUTOFBOUNDEXCEPTION_H
