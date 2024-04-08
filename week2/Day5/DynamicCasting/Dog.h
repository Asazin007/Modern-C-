#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include<iostream>

class Dog:public Animal{
private:
int m_speed;
public: 
    Dog() = delete;
    Dog(const Dog &) = delete; // disabled copy constructor
    Dog(Dog &&) = delete; // disabled move constructor brand new in C++11
    Dog &operator=(const Dog &) = delete; // disabled assignment operator
    Dog &operator=(Dog &&) = delete;	  // disabled assignment move operator brand new in C++11
    Dog(int legs,bool fly,int speed);
    ~Dog() = default;
    void who();
    int speed() const { return m_speed; }
    void setSpeed(int speed) { m_speed = speed; }

    void vioce() override;
    friend std::ostream &operator<<(std::ostream &os, const Dog &rhs);

    
};

#endif // DOG_H
