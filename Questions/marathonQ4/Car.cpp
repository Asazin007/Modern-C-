#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_name: " << rhs._name
       << " _acceleraton: " << rhs._acceleraton
       << " _top_speed: " << rhs._top_speed
       << " _ex_showroom_price: " << rhs._ex_showroom_price;
    return os;
}

Car::Car(std::string name, int acceleration, int top_speed, float price)
:_name(name),_acceleraton(acceleration),_top_speed(top_speed),_ex_showroom_price(price) //member list initialization sintax
{}  

