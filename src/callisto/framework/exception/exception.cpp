// parent header
#include <callisto/framework/exception/exception.hpp>

namespace c_f = callisto::framework;


template<>
const char* c_f::basic_exception<char>::get_unknown_str_exception() 
{ 
    return "Unknown exception."; 
}

template<>
const wchar_t* c_f::basic_exception<wchar_t>::get_unknown_str_exception() 
{ 
    return L"Unknown exception."; 
}
