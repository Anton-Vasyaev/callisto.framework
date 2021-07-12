#pragma once

// std
#include <sstream>
// project
#include "exception.hpp"


namespace callisto::framework
{
    template<typename type>
    class basic_string_builder_exception : public basic_exception<type>
    {
    public:
        using string_type = type;
    
    private:
        std::basic_string<string_type> error_message;

    public:
        template<typename... args_type>
        basic_string_builder_exception(
            const args_type&... args
        )
        {
            std::basic_stringstream<string_type> ss;

            ((ss << args), ...);

            this->error_message = std::move(ss.str());
        }

        virtual const string_type* what() const noexcept override
        {
            return error_message.data();
        }
    };

    using string_builder_exception = basic_string_builder_exception<char>;

    using wstring_builder_exception = basic_string_builder_exception<wchar_t>;
}
