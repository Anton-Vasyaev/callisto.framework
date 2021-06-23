//
// Copyright (c) 2019
// Vasyaev Anton
//
// std
#include <iostream>
// project
#include "shows/show_declarations.hpp"
#include <callisto/framework/native/numeric_type.hpp>

int main()
{
    show_exception();
    std::cout << "\n\n";
    show_platform_detect();
    std::cout << "\n\n";
    show_handlers();

    using namespace callisto;
    auto num_type =  framework::numeric::get_numeric_type_of<uint64_t>();

    std::cout << "numeric type:" << framework::numeric_type_str(framework::numeric_type::int32) << std::endl;

    std::cout << "Press key to exit...\n";
	std::getchar();
}