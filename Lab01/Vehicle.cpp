//
// Created by mrrys00 on 2/27/22.
//

#include "Vehicle.h"

int main(int argc, char** argv) {
    Vehicle vehicle1 = Vehicle();
    Vehicle vehicle2 = Vehicle("Seat", "KR6HA18", 105.0, 5);

    vehicle1.print();
    vehicle2.print();

    vehicle1.setMaxVelocityMPH(1);
    vehicle1.print();

    vehicle2.setNewName("Volvo");
    vehicle2.print();

    int carGroupID = vehicle1.getUniqueVehicleGroupID();
    std::cout << carGroupID << std::endl;

    return 0;
}