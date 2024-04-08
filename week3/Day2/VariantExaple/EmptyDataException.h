#ifndef EMPTYDATAEXCEPTION_H
#define EMPTYDATAEXCEPTION_H

#include <future>
#include <cstring>

class EmptyDataException : public std::future_error
{
private:
    char* m_msg;
public:
    EmptyDataException(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    EmptyDataException(const EmptyDataException&) = delete;
    EmptyDataException(EmptyDataException&&) noexcept = default;
    EmptyDataException& operator=(const EmptyDataException&) = delete;
    EmptyDataException&& operator=(EmptyDataException&&) = delete;

    ~EmptyDataException() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // EMPTYDATAEXCEPTION_H
