//
// Created by Tymur on 5/26/2025.
//

#include "editor_main.h"
#include "version.h"
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "DreamEngine version: " << DREAMENGINE_VERSION << std::endl;
}


/// @brief Adds two integers and prints the result to the console.
/// @param a First integer to add.
/// @param b Second integer to add.
void add(int a, int b)
{
    std::cout << "Sum: " << (a + b) << std::endl;
}