//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_MACRO_DETECT_H
#define CALLISTO_MACRO_DETECT_H

//
// DETECT OS
#if defined(_WIN64) || defined(_WIN32)
#define MACRO_DETECT_WINDOWS
#endif

#if defined(__linux__)
#define MACRO_DETECT_LINUX
#endif


//
// DETECT ARCHITECTURE
//
#if defined(__i386__) || defined(_M_IX86) || defined(_MI86)
    #define MACRO_DETECT_I386
#endif

#if defined(_M_AMD64) || defined(__amd64__)
    #define MACRO_DETECT_AMD64
#endif

#if defined(MACRO_DETECT_I386) || defined(MACRO_DETECT_AMD64)
    #define MACRO_DETECT_CPUX86
#endif


// DETECT BIT DESIGN
#if defined(MACRO_DETECT_LINUX)
    #if defined(__amd64__)
        #define MACRO_DETECT_64BIT
    #else
        #define MACRO_DETECT_32BIT
    #endif
#endif

#if defined(MACRO_DETECT_WINDOWS)
    #if defined(_WIN64)
        #define MACRO_DETECT_64BIT
    #else
        #define MACRO_DETECT_32BIT
    #endif
#endif

#endif