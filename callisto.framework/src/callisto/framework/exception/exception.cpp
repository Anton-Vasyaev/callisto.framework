// parent header
#include <callisto/framework/exception/exception.hpp>


namespace callisto::framework
{

template<>
const char* basic_exception<char>::get_unknown_str_exception() 
{ 
    return "Unknown exception."; 
}

template<>
const wchar_t* basic_exception<wchar_t>::get_unknown_str_exception() 
{ 
    return L"Unknown exception."; 
}
}