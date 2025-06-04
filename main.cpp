#include <iostream>
#include "SystemRegister.h"

int main() {
    SystemRegister system;

    try {
        system.loadFromCSV("courses.csv", "members.csv");
        system.displaySystem();
    } catch (const std::exception& ex) {
        std::cerr << "Σφάλμα: " << ex.what() << std::endl;
    }

    return 0;
}

