#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP

#include <stdexcept>
#include <cstring>
class StackEmptyException :public std::exception
{
private:
    char *_msg;

public:
    StackEmptyException(/* args */) = delete;
    StackEmptyException(const StackEmptyException &) = delete;
    StackEmptyException(StackEmptyException &&) = default;
    StackEmptyException &operator=(const StackEmptyException &) = delete;
    StackEmptyException &&operator=(StackEmptyException &&) = delete;

    explicit StackEmptyException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~StackEmptyException()
    {
        delete _msg;
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // STACKEMPTYEXCEPTION_HPP
