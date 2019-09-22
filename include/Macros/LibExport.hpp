//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef EXPORT_HPP
#define EXPORT_HPP

#include <Macros/Detect.hpp>


#ifdef MACRO_DETECT_WINDOWS
    #define CALLISTO_API __declspec( dllexport ) 
    #define CALLISTO_CALL __cdecl
#endif


#ifdef MACRO_DETECT_LINUX
    #define CALLISTO_API
    #define CALLISTO_CALL
#endif

#endif