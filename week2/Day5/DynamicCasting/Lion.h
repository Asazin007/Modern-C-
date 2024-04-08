#ifndef LION_H
#define LION_H
#include "Animal.h"
#include <iostream>
class Lion : public Animal
{
private:
    int m_speed;

public:
    Lion() = delete;
    Lion(const Lion &) = delete;            // disabled copy constructor
    Lion(Lion &&) = delete;                 // disabled move constructor brand new in C++11
    Lion &operator=(const Lion &) = delete; // disabled assignment operator
    Lion &operator=(Lion &&) = delete;      // disabled assignment move operator brand new in C++11
    Lion(int legs, bool fly, int speed);
    ~Lion() = default;

    int speed() const { return m_speed; }

    void vioce() override;

    friend std::ostream &
    operator<<(std::ostream &os, const Lion &rhs);
};

#endif // LION_H
