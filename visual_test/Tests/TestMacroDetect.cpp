//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <Tests/TestMacroDetect.hpp>
// test component
#include <Native/MacroDetect.h>
// std
#include <iostream>


void test_macro_detect()
{
// DETECT OS
#ifdef MACRO_DETECT_WINDOWS
    std::cout << "MACRO DETECT WINDOWS\n";
#endif

#ifdef MACRO_DETECT_LINUX
    std::cout << "MACRO DETECT LINUX\n";
#endif


// DETECT ARCHITECTURE
#ifdef MACRO_DETECT_I386
    std::cout << "MACRO DETECT i386\n";
#endif

#ifdef MACRO_DETECT_AMD64
    std::cout << "MACRO DETECT AMD64\n";
#endif

#ifdef MACRO_DETECT_CPUX86
    std::cout << "MACRO DETECT CPU x86\n";
#endif


// DETECT BIT DESIGN
#ifdef MACRO_DETECT_64BIT
    std::cout << "MACRO DETECT 64 bit\n";
#endif

#ifdef MACRO_DETECT_32BIT
    std::cout << "MACRO DETECT 32 bit\n";
#endif

}