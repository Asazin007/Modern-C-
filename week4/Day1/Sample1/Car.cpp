#include "Car.hpp"
/*
    constructor delegation: use multiple constructors OF THE SAME CLASS together to make the object
*/
Car::Car(CarType c1, std::string carId, std::string model, Engine_ptr engine) : carId{carId}, _model{model}, engine{engine}, c1{c1}
{
}

/*
    WE CANNOT USE DELEGATED CONSTRUCTORS AND MEMBER LIST INITIALISATION IN THE SAME CONSTRUCTORS
*/
Car::Car(CarType c1, std::string carId, float price, std::string model, Engine_ptr engine) : Car(c1, carId, model, engine)
{
    _price = price;
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
	os << "carId: " << rhs.carId
		<< " _price: " << rhs._price
		<< " _model: " << rhs._model;
		// << " engine: " << *rhs.engine;
	return os;
}


