#include <future>
#include <cstring>

class TEMP : public std::future_error
{
private:
    char* m_msg;
public:
    TEMP(std::future_errc error_type, const char* msg) : std::future_error{error_type} {
        m_msg = new char[strlen(msg) + 1];
        std::strcpy(m_msg, msg);
    }

    TEMP(const TEMP&) = delete;
    TEMP(TEMP&&) noexcept = default;
    TEMP& operator=(const TEMP&) = delete;
    TEMP&& operator=(TEMP&&) = delete;

    ~TEMP() {
        delete[] m_msg;
    }

    const char* what() const noexcept override {
        return m_msg;
    }
};