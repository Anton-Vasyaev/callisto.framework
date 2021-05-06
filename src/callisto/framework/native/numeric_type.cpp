// parent header
#include <callisto/framework/native/numeric_type.hpp>
// std
#include <sstream>
#include <iostream>
// project
#include <callisto/framework/exception/string_builder_exception.hpp>


namespace callisto::framework
{
const char* numeric_type_str(numeric_type numeric_type)
{
    switch(numeric_type)
    {
        case numeric_type::uint8:   return "uint8";
        case numeric_type::int8:    return "int8";

        case numeric_type::uint16:  return "uint16";
        case numeric_type::int16:   return "int16";

        case numeric_type::uint32:  return "uint32";
        case numeric_type::int32:   return "int32";

        case numeric_type::uint64:  return "uint64";
        case numeric_type::int64:   return "int64";

        case numeric_type::float32: return "float32";
        case numeric_type::float64: return "float64";

        default: return "none";
    }
}

size_t numeric::get_byte_size_of(numeric_type numeric_type)
{
    switch(numeric_type)
    {
        case numeric_type::uint8:
        case numeric_type::int8:
            return 1;

        case numeric_type::uint16:
        case numeric_type::int16:
            return 2;
        
        case numeric_type::uint32:
        case numeric_type::int32:
        case numeric_type::float32:
            return 4;

        case numeric_type::uint64:
        case numeric_type::int64:
        case numeric_type::float64:
            return 8;

        default:
            throw string_builder_exception(
                "failed to get_byte_size_of. Not valid numeric_type, code:", 
                numeric_type, "."
            );
    }
};


#define DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(type)                   \
    template<>                                                          \
    numeric_type numeric::get_numeric_type_of<numeric::type>()          \
    {                                                                   \
        return numeric_type::type;                                      \
    }                                                                   \
                                                                        \
    template<>                                                          \
    numeric_type numeric::get_numeric_type_of<const numeric::type>()    \
    {                                                                   \
        return numeric_type::type;                                      \
    }                                                                   \


DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(uint8);
DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(int8);

DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(uint16);
DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(int16);

DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(uint32);
DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(int32);

DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(uint64);
DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(int64);

DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(float32);
DECLARE_GET_NUMERIC_TYPE_SPECIALIZATION(float64);
}