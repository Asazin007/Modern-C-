#ifndef DATETIME_H
#define DATETIME_H
#include "Month.h"
#include <iostream>

class DateTime
{
private:
    std::string m_day;
    Month m_month;
    std::string m_year;
    std::string m_hours;
    std::string m_min;    
    
public:

//special function
    DateTime(/* args */)=delete ;
    DateTime(const DateTime&)=delete;
    DateTime(const DateTime&&)= delete;
    DateTime  operator=(const DateTime &)= delete;
    DateTime operator = (const DateTime&&)=delete;
    DateTime(std::string day, Month month, std::string year,std::string hours, std::string min);
    ~DateTime() =default;
    
//getters and setters
    std::string day() const { return m_day; }
    void setDay(const std::string &day) { m_day = day; }

    Month month() const { return m_month; }
    void setMonth(const Month &month) { m_month = month; }

    std::string year() const { return m_year; }
    void setYear(const std::string &year) { m_year = year; }

    std::string hours() const { return m_hours; }
    void setHours(const std::string &hours) { m_hours = hours; }

    std::string min() const { return m_min; }
    void setMin(const std::string &min) { m_min = min; }

    std::string getMonthString() const;
    friend std::ostream &operator<<(std::ostream &os, const DateTime &rhs);

    
};
#endif // DATETIME_H
