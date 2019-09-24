//
// Copyright (c) 2019
// Vasyaev Anton
//

#ifndef HOLD_STRING_EXCEPTION_HPP
#define HOLD_STRING_EXCEPTION_HPP

// std
#include <string>
#include <exception>

namespace Callisto
{
    namespace Framework
    {
        class HoldStringException : public std::exception
        {
        private:
            std::string errorMessage;

        public:
            HoldStringException(std::string& errorMessage);

            HoldStringException(std::string&& errorMessage);

            HoldStringException(const char* errorMessage);

            virtual const char* what() const override;

            const std::string& GetMessage() const;

            void MoveMessageTo(std::string& message);
        };
    }
}

#endif