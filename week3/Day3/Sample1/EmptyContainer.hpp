#ifndef EMPTYCONTAINER_HPP
#define EMPTYCONTAINER_HPP

#include <stdexcept>
#include <cstring>
#include <future>

class EmptyContainerException : public std::future_error
{
    char *_msg;
    
// std::future_errc err;
public:
    EmptyContainerException() = delete;

    EmptyContainerException(const EmptyContainerException &) = delete; // disabled copy constructor

    EmptyContainerException(EmptyContainerException &&) = default; // disabled move constructor brand new in C++11

    EmptyContainerException &operator=(const EmptyContainerException &) = delete; // disabled assignment operator
    EmptyContainerException &operator=(EmptyContainerException &&) = delete;      // disabled assignment move operator brand new in C++11

    EmptyContainerException(std::future_errc err, const char *msg)
    :std::future_error{err}
    {
        _msg = new char[strlen(msg)];
        strcpy(_msg, msg);
    }
    virtual const char *what() const noexcept override
    {
        return _msg;
    }

    ~EmptyContainerException()
    {
        delete _msg;
    }
};
#endif // EMPTYCONTAINER_HPP
