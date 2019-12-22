//
// Copyright (c) 2019
// Vasyaev Anton
//

#ifndef CALLISTO_FRAMEWORK_HOLD_STRING_EXCEPTION_HPP
#define CALLISTO_FRAMEWORK_HOLD_STRING_EXCEPTION_HPP

// std
#include <string>
#include <exception>
// project
#include <callisto/framework/native/lib_export.h>


namespace callisto::framework
{
    class CALLISTO_EXPORT HoldStringException : public std::exception
    {
    private:
        std::string error_message;

    public:
        CALLISTO_CALL HoldStringException(std::string& errorMessage);

		CALLISTO_CALL HoldStringException(std::string&& errorMessage);

		CALLISTO_CALL HoldStringException(const char* errorMessage);

        virtual const char* CALLISTO_CALL what() const noexcept override;
        const std::string& CALLISTO_CALL get_error_message() const;

        void CALLISTO_CALL move_message_to(std::string& message);
    };
}

#endif