#ifndef CARD_HPP
#define CARD_HPP
#include "Date.hpp"
#include <iostream>
#include <memory>
class Card
{
private:
    long long int m_cardno;
    int m_cvv;
    std::shared_ptr<Date> m_date;
    static int m_gen;
    
public:
    Card();
    Card(const Card &) = delete;            // disabled copy constructor
    Card(Card &&) = delete;                 // disabled move constructor brand new in C++11
    Card &operator=(const Card &) = delete; // disabled assignment operator
    Card &operator=(Card &&) = delete;      // disabled assignment move operator brand new in C++11
    Card(
        
        std::shared_ptr<Date> m_date_

    );
    ~Card() = default;

    friend std::ostream &operator<<(std::ostream &os, const Card &rhs);
};

#endif // CARD_HPP
