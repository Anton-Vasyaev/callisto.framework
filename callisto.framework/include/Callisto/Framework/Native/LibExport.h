//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_EXPORT_H
#define CALLISTO_EXPORT_H

#include <Callisto/Framework/Native/MacroDetect.h>


#ifdef MACRO_DETECT_WINDOWS
    #define CALLISTO_EXPORT		__declspec( dllexport ) 
    #define CALLISTO_CALL		__cdecl
#endif


#ifdef MACRO_DETECT_LINUX
    #define CALLISTO_EXPORT     //__attribute__((visibility("default")))
    #define CALLISTO_CALL       //__attribute__ ((__cdecl__))
#endif

#endif