#include "car.h"
#include <iostream>
#include <string>
#include <iterator>

using namespace std;


Car::Car(int id, std::string make, std::string model, int year, std::string condition) : id(id), make(make), model(model), year(year), condition(condition), rented(false) {}

Car::Car() {}

int Car::getID() const {
	return id;
}

std::string Car::getMake() const {
	return  make;
}

std::string Car::getModel() const {
	return  model;
}

int Car::getYear() const {
	return  year;
}

std::string Car::getCondition() const {
	return  condition;
}

bool Car::isRented() {
	return  rented;
}

void Car::setCondition(std::string condition) {
	this->condition = condition;
}

void Car::toggleRented() {
	rented = !rented;
}
void Car::displayCar() {
	// While the Car is already rented
	while (rented == true) {
		std::cout << "ID: " << id << ", " << make << ", " << model << ", " << year << ", " << condition << " is not available" << std::endl;
		// If the Car is not rented
		if (rented == false) {
			std::cout << "ID: " << id << ", " << make << ", " << model << ", " << year << ", " << condition << " is available" << std::endl;
		}
	}

}