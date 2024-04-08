#ifndef CustomFuture_HPP
#define CustomFuture_HPP

#include <future>
#include <cstring>

class CustomFuture : public std::future_error
{
private:
    char* m_msg;
public:
    CustomFuture(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    CustomFuture(const CustomFuture&) = delete;
    CustomFuture(CustomFuture&&) noexcept = default;
    CustomFuture& operator=(const CustomFuture&) = delete;
    CustomFuture&& operator=(CustomFuture&&) = delete;

    ~CustomFuture() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};

#endif // CustomFuture_HPP