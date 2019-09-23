#ifndef CALLISTO_RUNTIME_EXCEPTION_HPP
#define CALLISTO_RUNTIME_EXCEPTION_HPP

// std
#include <string>
#include <exception>

namespace Callisto
{
    namespace Exception
    {
        class RuntimeException : std::exception
        {
        private:
            std::string errorMessage;

        public:
            RuntimeException(std::string& errorMessage);

            RuntimeException(std::string&& errorMessage);

            virtual const char* what() const override;

            const std::string& GetMessage() const;

            void MoveMessageTo(std::string& message);
        };
    }
}

#endif