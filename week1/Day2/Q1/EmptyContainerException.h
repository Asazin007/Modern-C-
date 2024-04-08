#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>
#include <cstring>
class EmptyContainerException : public std::exception
{
private:
    char *_msg;

public:
    EmptyContainerException(/* args */) = delete;
    EmptyContainerException(const EmptyContainerException &) = delete;
    EmptyContainerException(EmptyContainerException &&) = default;
    EmptyContainerException &operator=(const EmptyContainerException &) = delete;
    EmptyContainerException &&operator=(EmptyContainerException &&) = delete;

    EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~EmptyContainerException()
    {
        delete _msg;
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};
#endif // EMPTYCO