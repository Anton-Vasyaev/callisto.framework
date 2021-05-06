//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include "show_declarations.hpp"
// test component
#include <callisto/framework/native/platform_detect.h>
// std
#include <iostream>


#define CALLISTO_PIDOR "PIDOR"

void show_platform_detect()
{
// DETECT OS
    std::cout << "OS:                   " << CALLISTO_OS_NAME << std::endl;
    std::cout << "OS FAMILY:            " << CALLISTO_OS_FAMILY_NAME << std::endl;
    std::cout << "ARCHITECTURE:         " << CALLISTO_ARCHITECTURE_NAME << std::endl;
    std::cout << "ARCHITECTURE FAMILY:  " << CALLISTO_ARCHITECTURE_FAMILY_NAME << std::endl;
    std::cout << "BIT DESIGN:           " << CALLISTO_BIT_DESIGN_NAME << std::endl;
 
}