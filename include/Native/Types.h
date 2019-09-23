//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_TYPES_H
#define CALLISTO_TYPES_H

// macro
#include <Native/MacroDetect.h>
// std
#include <cstdint>



typedef int8_t      t_int8;
typedef uint8_t     t_uint8;
typedef int8_t      t_byte;
typedef uint8_t     t_ubyte;

typedef int16_t     t_int16;
typedef int16_t     t_uint16;

typedef int32_t     t_int32;
typedef uint32_t    t_uint32;

typedef int64_t     t_int64;
typedef uint64_t    t_uint64;

typedef float       t_float32;
typedef double      t_float64;


#ifdef MACRO_DETECT_64BIT
typedef uint64_t t_size;
typedef int64_t t_ssize;
#else
typedef uint32_t t_size;
typedef int32_t t_ssize;
#endif

#endif