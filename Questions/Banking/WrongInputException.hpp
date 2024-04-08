#ifndef WRONGINPUTEXCEPTION_HPP
#define WRONGINPUTEXCEPTION_HPP

#include <stdexcept>
#include <cstring>
class WrongInputException : public std::exception
{
    char *_msg;

public:
    WrongInputException() = delete;

    WrongInputException(const WrongInputException &) = delete; // disabled copy constructor

    WrongInputException(WrongInputException &&) = default; // disabled move constructor brand new in C++11

    WrongInputException &operator=(const WrongInputException &) = delete; // disabled assignment operator
    WrongInputException &operator=(WrongInputException &&) = delete;      // disabled assignment move operator brand new in C++11

    WrongInputException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~WrongInputException()
    {
        delete _msg;
    }

    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // WRONGINPUTEXCEPTION_HPP
