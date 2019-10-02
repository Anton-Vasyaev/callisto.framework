//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_EXPORT_H
#define CALLISTO_EXPORT_H

#include <Callisto/Native/MacroDetect.h>


#ifdef MACRO_DETECT_WINDOWS
    #define CALLISTO_EXPORT		__declspec( dllexport ) 
    #define CALLISTO_CALL		__cdecl
#endif


#ifdef MACRO_DETECT_LINUX
    #define CALLISTO_API
    #define CALLISTO_CALL
#endif

#endif