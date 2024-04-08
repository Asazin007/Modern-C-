#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>
#include <cstring>
class EmptyContainerException : public std::exception
{
    char *_msg;
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }

public:
    EmptyContainerException() = delete;

    EmptyContainerException(const EmptyContainerException &) = delete; // disabled copy constructor

    EmptyContainerException(EmptyContainerException &&) = default; // disabled move constructor brand new in C++11

    EmptyContainerException &operator=(const EmptyContainerException &) = delete; // disabled assignment operator
    EmptyContainerException &operator=(EmptyContainerException &&) = delete;      // disabled assignment move operator brand new in C++11

    EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~EmptyContainerException()
    {
        delete _msg;
    }

    
};

#endif // EMPTYCONTAINEREXCEPTION_H
