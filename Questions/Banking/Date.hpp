#ifndef DATE_HPP
#define DATE_HPP

#include<iostream>
class Date{
private:
int m_month{2};
int m_year{2024};
public: 
    Date() = default;
    Date(const Date &) = delete; // disabled copy constructor
    Date(Date &&) = delete; // disabled move constructor brand new in C++11
    Date &operator=(const Date &) = delete; // disabled assignment operator
    Date &operator=(Date &&) = delete;
    Date(int month,int year);	  // disabled assignment move operator brand new in C++11
    ~Date() = default;

    int month() const { return m_month; }
    void setMonth(int month) { m_month = month; }

    int year() const { return m_year; }
    void setYear(int year) { m_year = year; }

    friend std::ostream &operator<<(std::ostream &os, const Date &rhs);
};

#endif // DATE_HPP
