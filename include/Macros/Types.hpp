//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef TYPES_HPP
#define TYPES_HPP

// macro
#include <Macros/Detect.hpp>
// std
#include <cstdint>



using t_int8 = int8_t;
using t_uint8 = uint8_t;
using t_byte = t_int8;
using t_ubyte = t_uint8;

using t_int16 = int16_t;
using t_uint16 = int16_t;

using t_int32 = int32_t;
using t_uint32 = uint32_t;

using t_int64 = int64_t;
using t_uint64 = uint64_t;

using t_float32 = float;
using t_float64 = double;


#ifdef MACRO_DETECT_64BIT
using t_size = uint64_t;
using t_ssize = int64_t;
#else
using t_size = uint32_t;
using t_ssize = int32_t;
#endif

#endif