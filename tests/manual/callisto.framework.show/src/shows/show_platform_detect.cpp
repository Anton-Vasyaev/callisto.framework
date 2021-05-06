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
    std::cout << "OS:" << CALLISTO_PIDOR << std::endl;

}