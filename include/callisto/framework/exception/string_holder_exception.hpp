#pragma once

// std
#include <sstream>
// project
#include "exception.hpp"

namespace callisto::framework
{
    template<typename _char_type>
    class basic_string_holder_exception : public basic_exception<_char_type>
    {
    public:
        using char_type = _char_type;
    private:
        // data
        std::basic_string<char_type> _error_message;

    public:
        // construct and destruct
        basic_string_holder_exception(const std::basic_string<char_type>& error_message)
        {
            this->_error_message = error_message;
        }

        basic_string_holder_exception(const std::basic_string<char_type>&& error_message)
        {
            this->_error_message = std::move(error_message);
        }

        basic_string_holder_exception(const char_type* error_message)
        {
            this->_error_message = std::basic_string<char_type>(error_message);
        }

        virtual const char* what() const noexcept override
        {
            return (char*)_error_message.data();
        }
    };

    using string_holder_exception     = basic_string_holder_exception<char>;
    using wstring_holder_exception    = basic_string_holder_exception<wchar_t>;
}