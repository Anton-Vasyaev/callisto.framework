//
// Copyright (c) 2019
// Vasyaev Anton
//
// std
#include <iostream>
// project
#include <shows/show_declarations.hpp>

int main()
{
    show_exception();
    std::cout << "\n\n";
    show_platform_macros();
    std::cout << "\n\n";
    show_unique_handler();

    std::cout << "Press key to exit...\n";
	std::getchar();
}