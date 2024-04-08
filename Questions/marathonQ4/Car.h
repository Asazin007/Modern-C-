#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
private:
    /* data */
    std::string _name{""};
    int _acceleraton{0};
    int _top_speed{0};
    float _ex_showroom_price{0.0f};

public:
    // default constructor enabled
    Car() = default;
    Car(const Car &) = delete; // not needed don't create , delete it
    virtual ~Car() = default;  // default constructor
    // there R 6 special member func , you have to set ,use or not, (enble or disable something)
    Car(Car &&) = delete;                 // disable move constructor,this is new features in cpp
    Car &operator=(const Car &) = delete; // no loophole
    Car &operator=(Car &&) = delete;      // cpp new, delete move assignment operator

    Car(std::string name, int acceleration, int top_speed, float price);
    // setters and getters
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleraton() const { return _acceleraton; }
    void setAcceleraton(int acceleraton) { _acceleraton = acceleraton; }

    int topSpeed() const { return _top_speed; }
    void setTopSpeed(int top_speed) { _top_speed = top_speed; }

    float exShowroomPrice() const { return _ex_showroom_price; }
    void setExShowroomPrice(float ex_showroom_price) { _ex_showroom_price = ex_showroom_price; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    virtual float Drive() = 0;
};

#endif // CAR