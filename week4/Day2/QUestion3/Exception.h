#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <future>
#include <cstring>

class Exception : public std::future_error
{
private:
    char* m_msg;
public:
    Exception(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    Exception(const Exception&) = delete;
    Exception(Exception&&) noexcept = default;
    Exception& operator=(const Exception&) = delete;
    Exception&& operator=(Exception&&) = delete;

    ~Exception() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // EXCEPTION_H
