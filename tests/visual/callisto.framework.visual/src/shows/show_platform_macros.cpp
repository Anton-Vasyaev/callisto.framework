//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <shows/show_declarations.hpp>
// test component
#include <callisto/framework/native/platform_macros.h>
// std
#include <iostream>


void show_platform_macros()
{
// DETECT OS
#ifdef CALLISTO_PLATFORM_WINDOWS
    std::cout << "MACRO DETECT WINDOWS\n";
#endif

#ifdef CALLISTO_PLATFORM_LINUX
    std::cout << "MACRO DETECT LINUX\n";
#endif


// DETECT ARCHITECTURE
#ifdef CALLISTO_PLATFORM_I386
    std::cout << "MACRO DETECT i386\n";
#endif

#ifdef CALLISTO_PLATFORM_AMD64
    std::cout << "MACRO DETECT AMD64\n";
#endif

#ifdef CALLISTO_PLATFORM_CPUX86
    std::cout << "MACRO DETECT CPU x86\n";
#endif


// DETECT BIT DESIGN
#ifdef CALLISTO_PLATFORM_64BIT
    std::cout << "MACRO DETECT 64 bit\n";
#endif

#ifdef CALLISTO_PLATFORM_32BIT
    std::cout << "MACRO DETECT 32 bit\n";
#endif

}