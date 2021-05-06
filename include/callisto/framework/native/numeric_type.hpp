#pragma once

// std
#include <cstddef>
#include <cstdint>
#include <string_view>

using float32_t = float;
using float64_t = double;

namespace callisto::framework
{
    enum numeric_type
    {
        unknown, 

        uint8,
        int8,

        uint16,
        int16,

        uint32,
        int32,

        uint64,
        int64,

        float32,
        float64,
    };

    const char* numeric_type_str(numeric_type numeric_type);

    struct numeric
    {
        using uint8     = uint8_t;
        using int8      = int8_t;

        using uint16    = uint16_t;
        using int16     = int16_t;

        using uint32    = uint32_t;
        using int32     = int32_t;

        using uint64    = uint64_t;
        using int64     = int64_t;

        using float32   = float;
        using float64   = double;


        template<typename T>
        static numeric_type get_numeric_type_of();

        static size_t get_byte_size_of(numeric_type numeric_type);

    };
}