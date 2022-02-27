//
// Created by mrrys00 on 2/27/22.
//

#ifndef CPP_VEHICLE_H
#define CPP_VEHICLE_H
#include <iostream>
#include <string>
#include <cstring>

//Zaimplementuj podaną na zajęciach klasę, zawierającą:
//zadane atrybuty,
//konstruktor bezparametrowy,
//konstruktor z parametrami (część z wartością domyślną),
//zadany zestaw metod dostępowych/modyfikujących obiekty klasy,
//metodę wypisz, wypisującą atrybuty obiektu na konsolę,
//zadany atrybut i metodę statyczną,

class Vehicle {
    // zadane atrybuty
    std::string name;
    char idNumber[7];
    double maxVelocityMPH;
    int passengerNumber;
    bool isValid;
private:
    void changeValidState(bool isValidNew) {
        this -> isValid = isValidNew;
    }
public:
    static int vehicleGroupID;
    // https://www.p-programowanie.pl/cpp/konstruktory
    //konstruktor bezparametrowy
    Vehicle() : name{"New vehicle"}, maxVelocityMPH{100.13}, passengerNumber{5}, isValid{true} { std::cout << "non parameter constructor" << std::endl; }

    //konstruktor z parametrami (część z wartością domyślną)
    Vehicle(std::string name, char* idNumber, double maxVelocityMPH, int passengerNumber = 5, bool isValid = true) {
        this -> name = name;
        strcpy(this -> idNumber, idNumber);
        this -> maxVelocityMPH = maxVelocityMPH;
        this -> passengerNumber = passengerNumber;
        this -> isValid = isValid;
        std::cout << "parameter constructor" << std::endl;
    }

    //zadany zestaw metod dostępowych/modyfikujących obiekty klasy
    void setNewName(std:: string name) {
        this -> name = name;
    }

    void setMaxVelocityMPH(double maxVelocityMPH) {
        this -> maxVelocityMPH = maxVelocityMPH;
        if (maxVelocityMPH < 0 || maxVelocityMPH >= 120) changeValidState(false);
        else changeValidState(true);
    }

    static int getUniqueVehicleGroupID() {
        return vehicleGroupID;
    }
    void print();
};

void Vehicle::print() {
    std::cout << "Vehicle name: " << this -> name << '\n' << "Vehicle ID: " << this -> idNumber << '\n' << "max velocity: " << this -> maxVelocityMPH << '\n' << "passenger number: " << this -> passengerNumber << '\n' << "Vehicle ID: " << this -> isValid << std::endl;
}

int Vehicle::vehicleGroupID = 0;

#endif //CPP_VEHICLE_H
