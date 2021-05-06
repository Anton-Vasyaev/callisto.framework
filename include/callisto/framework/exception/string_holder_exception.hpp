#pragma once

// std
#include <sstream>
#include <exception>

namespace callisto::framework
{
    template<typename T>
    class basic_string_holder_exception : public std::exception
    {
    public:
        using string_type = T;
    private:
        // data
        std::basic_string<string_type> _error_message;

    public:
        // construct and destruct
        basic_string_holder_exception(const std::basic_string<string_type>& error_message)
        {
            this->_error_message = error_message;
        }

        basic_string_holder_exception(const std::basic_string<string_type>&& error_message)
        {
            this->_error_message = std::move(error_message);
        }

        basic_string_holder_exception(const string_type* error_message)
        {
            this->_error_message = std::basic_string<string_type>(error_message);
        }

        virtual const char* what() const noexcept override
        {
            return (char*)_error_message.data();
        }
    };

    using string_holder_exception     = basic_string_holder_exception<char>;
    using wstring_holder_exception    = basic_string_holder_exception<wchar_t>;
}