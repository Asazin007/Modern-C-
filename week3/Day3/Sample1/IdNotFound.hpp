#ifndef IDNOTFOUND_HPP
#define IDNOTFOUND_HPP


#include <stdexcept>
#include <cstring>
#include <future>
class IdNotFound : public std::future_error
{
    char *_msg;
    virtual const char* what() const noexcept override
    {
        return _msg;
    }

public:
    IdNotFound() = delete;

    IdNotFound(const IdNotFound &) = delete; // disabled copy constructor

    IdNotFound(IdNotFound &&) = default; // enabled move constructor brand new in C++11

    IdNotFound &operator=(const IdNotFound &) = delete; // disabled assignment operator
    IdNotFound &operator=(IdNotFound &&) = delete;      // disabled assignment move operator brand new in C++11

    IdNotFound(std::future_errc err, const char *msg):
    std::future_error{err}
    {
        _msg = new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    ~IdNotFound()
    {
        delete _msg;
    }
};



#endif // IDNOTFOUND_HPP
