#ifndef ANIMAL_H
#define ANIMAL_H

#include<iostream>
class Animal{
private:
    int m_legs;
    bool m_can_fly;


public: 
    Animal() = delete;
    Animal(const Animal &) = delete; // disabled copy constructor
    Animal(Animal &&) = delete; // disabled move constructor brand new in C++11
    Animal &operator=(const Animal &) = delete; // disabled assignment operator
    Animal &operator=(Animal &&) = delete;	  // disabled assignment move operator brand new in C++11
    Animal(int legs, bool canfly);
    virtual ~Animal() = default;
    virtual void vioce()=0;

    int legs() const { return m_legs; }
    void setLegs(int legs) { m_legs = legs; }

    bool canFly() const { return m_can_fly; }
    void setCanFly(bool can_fly) { m_can_fly = can_fly; }

    friend std::ostream &operator<<(std::ostream &os, const Animal &rhs);
};

#endif // ANIMAL_H
