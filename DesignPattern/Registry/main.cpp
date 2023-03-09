#include <iostream>

#include "registry.h"

int main() {
    int x = 0, y = 0;
    float pi;
    RegistryManager::Global()->getValue("int_1", x);
    RegistryManager::Global()->getValue("int_2", y);
    RegistryManager::Global()->getValue("pi", pi);
    std::cout << "value x = " << x << ", y = " << y << ", pi = " << pi << "\n";
    return 0;
}