#ifndef CAR_HPP
#define CAR_HPP
#include <iostream>
#include "Engine.hpp"
#include <memory>
#include "CarType.hpp"

using Engine_ptr = std::shared_ptr<Engine>;
class Car
{
private:
	std::string carId{""};
	float _price{0.0f};
	std::string _model{""};
	Engine_ptr engine;
	CarType c1;


public:
	Car() = delete;

	Car(const Car &) = delete; // disabled copy constructor

	Car(Car &&) = delete; // disabled move constructor brand new in C++11

	Car &operator=(const Car &) = delete; // disabled assignment operator
	Car &operator=(Car &&) = delete;	  // disabled assignment move operator brand new in C++11

	~Car() = default;
	Car(CarType c1,std::string carId, float price, std::string model, Engine_ptr engine);
	Car(CarType c1,std::string carId, std::string model, Engine_ptr engine);

	std::string getCarId() const { return carId; }
	void setCarId(const std::string &carId_) { carId = carId_; }

	float price() const { return _price; }
	void setPrice(float price) { _price = price; }

	std::string model() const { return _model; }
	void setModel(const std::string &model) { _model = model; }

	Engine_ptr getEngine() const { return engine; }
	void setEngine(const Engine_ptr &engine_) { engine = engine_; }

	CarType getC1() const { return c1; }
	void setC1(const CarType &c1_) { c1 = c1_; }

	

	

	

	friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

	
};

#endif