#ifndef _CAR_H_
#define _CAR_H_

#include <iomanip>
#include <string>
#include <iterator>

using namespace std;

class Car {

public:
	// Getters
	int getID() const;					// returns the ID of the car as an int
	std::string getMake() const;		// returns the make of the car as a string
	std::string getModel() const;		// returns the model of the car as a string
	int getYear() const;				// returns the year of the car as an int
	std::string getCondition() const;	// returns the condition of the car as a string
	bool isRented();					// returns the value of rented as a bool

	// Setters
	void setCondition(std::string condition);		// takes a string for the condition and assigns it to condition
	void toggleRented();							// toggles the value of rented.If rented is true then it changes it to false. If rented is false then it changes it to true.

	void displayCar();								// this function should display the information for a car.

	// Parameterize constructor
	Car(int id, std::string make, std::string model, int year, std::string condition);
	Car();

	// Declares operator << as a friend global function
	friend std::ostream& operator<<(std::ostream& os, const Car& car) {
		os << "ID: " << car.id << ", " << car.make << " " << car.model << ", " << car.year << ", " << car.condition << "," << " is available";

		return os;
	}

private:
	// All variables except rented are intialized by the parameterized constructor
	int id;
	std::string make;
	std::string model;
	int year;
	std::string condition;  // The possible values of condition are new, slightly_used, and used
	bool rented;			// initialized by the constructor to false, this will not be parameterized

};
#endif 