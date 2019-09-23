// parent header
#include <Exception/RuntimeException.hpp>



#pragma region ConstructAndDestruct

Callisto::Exception::RuntimeException::RuntimeException(
    std::string& errorMessage
)
{
    this->errorMessage = errorMessage;
}

Callisto::Exception::RuntimeException::RuntimeException(
    std::string&& errorMessage
)
{
    this->errorMessage = std::move(errorMessage);
}

#pragma endregion


#pragma region Methods

const char* Callisto::Exception::RuntimeException::what() const
{
    return this->errorMessage.c_str();
}

const std::string& Callisto::Exception::RuntimeException::GetMessage() const
{
    return this->errorMessage;
}

void Callisto::Exception::RuntimeException::MoveMessageTo(std::string& message)
{
    message = std::move(this->errorMessage);
}

#pragma endregion