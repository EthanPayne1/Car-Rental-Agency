/*
Ethan Payne
12/05/21
Car Rental Agency
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "car.h"

// Function Headers
void addCar(vector<Car>& cars);
bool deleteCar(vector<Car>& cars);
bool updateCarCondition(vector<Car>& cars);
void displayCar(const vector<Car>& cars);
void displayAllCars(const vector<Car>& cars);
bool rentCar(vector<Car>& cars);
bool returnCar(vector<Car>& cars);

// Builds the car Menu
void PrintMenu() {
    cout << "CAR RENTAL AGENCY MENU" << endl;
    cout << "a - Add car to inventory\n"
        << "d - Delete car by id from inventory\n"
        << "u - Update car by id condition in inventory\n"
        << "s - Display one car by id from inventory\n"
        << "i - Display list of all cars in inventory\n"
        << "c - Rent a car by id in inventory\n"
        << "r - Return a car by id to inventory\n"
        << "q - Quit" << endl;
}

// addCar() has the user enter the id, make, model, year, and condition of the car
// A car object is instantiated and added to the vector  
void addCar(vector<Car>& cars) {
    int id;
    int year;
    std::string make;
    std::string model;
    std::string condition;
    Car car;
    std::cout << "ADD CAR TO INVENTORY" << std::endl;
    std::cout << "Enter an ID:" << std::endl;
    cin >> id;
    cin.ignore();
    std::cout << "Enter the make:" << std::endl;
    cin >> make;
    std::cout << "Enter the model:" << std::endl;
    cin >> model;
    std::cout << "Enter the year:" << std::endl;
    cin >> year;
    cin.ignore();
    std::cout << "Enter the condition (new, slightly_used, used):" << std::endl;
    cin >> condition;
    cout << endl;
    cars.emplace_back(id, make, model, year, condition);
}

// deleteCar() takes the ID from the user and deletes the car from the vector 
// If the ID is found and the car is removed then the function will return true otherwise the function will return false
bool deleteCar(vector<Car>& cars) {
    int id;
    std::cout << "REMOVE CAR FROM INVENTORY" << std::endl;
    std::cout << "Enter the ID of the car to delete:" << std::endl << std::endl;
    cin >> id;
    if (id > -1) { // Searches throught the vector find the ID so it can remove the car using a lambda function
        cars.erase(std::remove_if(cars.begin(), cars.end(),
            [id](auto c) {
                return id == c.getID();
            }), cars.end());
        return true; // The ID is found and the car is deleted so the function is returning true
    }
    else {
        return false; // ID isnt found so return false
    }
}

// updateCarCondition() takes the ID and condition of a car from a user then updates the condition
// If the ID is found and the condition is updated then updateCarCondition will return true
// If the ID is not found then updateCarCondition will return false
bool updateCarCondition(vector<Car>& cars) {
    int id;
    std::string condition;
    Car car;
    std::cout << "UPDATE CAR CONDITION IN INVENTORY" << std::endl;
    std::cout << "Enter the ID of the car to update condition:" << std::endl;
    cin >> id;
    std::cout << "Enter the condition (new, slightly_used, used):" << std::endl << std::endl;
    cin >> condition;
    if (id > -1) { // Searches through the vector with a lambda function to find the ID then returns ID equal to getID()
        auto iter = std::find_if(cars.begin(), cars.end(), // Assign the iterator to search through the vector
            [id](auto c) {
                return id == c.getID();
            });
        if (iter == cars.end()) { // If the iterator reaches the end of the vector then return 0
            return 0;
        }
        iter->setCondition(condition); // The condition has been updated so return true
        cars.emplace_back(car);
        return true;
    }
    else {
        return false;
    }
}

// Have the user enter the ID and then find the ID in the vector and display the cars information
void displayCar(const vector<Car>& cars) {
    Car car;
    int id;
    string condition;

    std::cout << "DISPLAY CAR IN INVENTORY" << std::endl;
    std::cout << "Enter the ID of the car to display:" << std::endl << std::endl;
    cin >> id;

    if (id > -1) { // Searches through the vector to find the correct ID 
        auto iter = std::find_if(cars.begin(), cars.end(),
            [id](auto c) {
                return id == c.getID();
            });

        for (const auto& i : cars)
            cout << i << endl << endl;

    }

}

// Displays all the information for each car inside the vector
void displayAllCars(const vector<Car>& cars) {

    cout << "DISPLAY ALL CARS IN INVENTORY" << endl;
    for (const auto& i : cars)
        cout << i << endl;
    cout << endl;

}

// rentCar() has the user enter an ID for the car they want to rent 
// The function will then find the ID inside the vector
// If the car is not already rented the rentCar() will toggle the rent status of the car 
bool rentCar(vector<Car>& cars) {
    Car car;
    int id;
    cout << "RENT CAR IN INVENTORY\n";
    cout << "Enter the ID of the car to rent:" << endl;
    cin >> id;
    cin.ignore();
    cout << endl;

    for (Car& car : cars) {
        if (car.getID() == id) {
            if (car.isRented()) { // If the ID is found check if the car is already rented and return false if already rented 
                car.toggleRented();
                cout << "Car is already rented" << endl << endl;
                return false;
            }
            else {
                car.toggleRented(); // Else if the car isn't already rented then call toggleRented() to change the isRented status
                cout << "Car rented successfully" << endl << endl;
                return true; // Return true if the not already rented 
            }
        }

    }
    cout << "Car " << id << " not found in inventory" << endl << endl;
    return false; // If you cant find the ID then return false 
}

// Same method as rentCar() but returns true when the car is returned and returns false if the car hasnt been rented or ID isnt find
bool returnCar(vector<Car>& cars) {
    int id;
    cout << "RETURN CAR TO INVENTORY" << endl;
    cout << "Enter the ID of the car to return:" << endl;
    cin >> id;

    for (Car& car : cars) {
        if (car.getID() == id) {
            if (car.isRented()) {
                car.toggleRented();
                cout << "Car returned successfully" << endl << endl;
                return true;
            }
            else {
                car.toggleRented();
                cout << "Car has not been rented" << endl << endl;
                return false;
            }
        }
    }
    cout << "Car " << id << " not found in inventory" << endl << endl;
    return false;
}

int main() {

    char option; // To hold the value of the input for the menu
    vector<Car> cars; // Variable for the vector 
    Car car;

    // Do/While loop for the switch statement that calls the PrintMenu() function
    do {
        PrintMenu();
        std::cout << "Choose an option:" << std::endl;
        cin >> option;
        cin.ignore();
        cout << endl;
        while (option != 'a' && option != 'd' && option != 'c' && option != 's' && option != 'i' && option != 'o'
            && option != 'u' && option && option != 'r' && option != 'q') {
            cout << "Choose an option:" << std::endl << std::endl;
            cin >> option;
        }
        // Switch statement that assigns each case with a function then breaks 
        // If the user enters q then the user exits the menu 
        switch (option) {
        case 'a':
            addCar(cars);
            break;
        case 'd':
            deleteCar(cars);
            break;
        case 'u':
            updateCarCondition(cars);
            break;
        case 's':
            displayCar(cars);
            break;
        case 'i':
            displayAllCars(cars);
            break;
        case 'c':
            rentCar(cars);
            break;
        case 'r':
            returnCar(cars);
            break;
        case 'q':
            cout << "Done" << endl;
            break;
        }

    } while (option != 'q');
}