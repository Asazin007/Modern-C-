#ifndef WRONGVALUEEXCEPTION_H
#define WRONGVALUEEXCEPTION_H

#include <stdexcept>
#include <cstring>
class WrongValueException : public std::exception
{
    char *_msg;
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }

public:
    WrongValueException() = delete;

    WrongValueException(const WrongValueException &) = delete; // disabled copy constructor

    WrongValueException(WrongValueException &&) = default; // disabled move constructor brand new in C++11

    WrongValueException &operator=(const WrongValueException &) = delete; // disabled assignment operator
    WrongValueException &operator=(WrongValueException &&) = delete;      // disabled assignment move operator brand new in C++11

    WrongValueException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~WrongValueException()
    {
        delete _msg;
    }

    
};

#endif // WRONGVALUEEXCEPTION_H
