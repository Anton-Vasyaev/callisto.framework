#pragma once

namespace callisto::framework
{
    template<typename char_type>
    class basic_exception
    {
    private:
        static const char_type* get_unknown_str_exception();

        const char_type* _error_message = nullptr;

    public:
        basic_exception()
        {
            this->_error_message = nullptr;
        }
        basic_exception(const char_type* error_message) : _error_message(error_message) { }

        virtual const char_type* what() const noexcept
        {
            return this->_error_message ? this->_error_message : get_unknown_str_exception();
        }
    };

    using exception  = basic_exception<char>;
    using wexception = basic_exception<wchar_t>;
}

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

