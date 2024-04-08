#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <cstring>
class IDnotfoundException : public std::exception
{
private:
    char *_msg;

public:
    IDnotfoundException(/* args */) = delete;
    IDnotfoundException(const IDnotfoundException &) = delete;
    IDnotfoundException(IDnotfoundException &&) = default;
    IDnotfoundException &operator=(const IDnotfoundException &) = delete;
    IDnotfoundException &&operator=(IDnotfoundException &&) = delete;

    IDnotfoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~IDnotfoundException()
    {
        delete _msg;
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // IDNOTFOUNDEXCEPTION_H
