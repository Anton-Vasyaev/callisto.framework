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
#include <Callisto/Framework/Native/LibExport.h>

namespace Callisto::Framework
{
    class CALLISTO_EXPORT HoldStringException : public std::exception
    {
    private:
        std::string errorMessage;

    public:
        CALLISTO_CALL HoldStringException(std::string& errorMessage);

		CALLISTO_CALL HoldStringException(std::string&& errorMessage);

		CALLISTO_CALL HoldStringException(const char* errorMessage);

        virtual const char* CALLISTO_CALL what() const noexcept override;

        const std::string& CALLISTO_CALL GetErrorMessage() const;

        void CALLISTO_CALL MoveMessageTo(std::string& message);
    };
}

#endif