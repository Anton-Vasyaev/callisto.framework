#pragma once

#include "platform_detect.h"


#ifdef CALLISTO_OS_WINDOWS
    #define CALLISTO_EXPORT		__declspec( dllexport ) 
    #define CALLISTO_CALL		__cdecl
#endif


#ifdef CALLISTO_OS_LINUX
    #define CALLISTO_EXPORT     //__attribute__((visibility("default")))
    #define CALLISTO_CALL       //__attribute__ ((__cdecl__))
#endif