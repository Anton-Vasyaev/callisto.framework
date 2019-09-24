//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <Exception/HoldStringException.hpp>



#pragma region ConstructAndDestruct

Callisto::Framework::HoldStringException::HoldStringException(
    std::string& errorMessage
)
{
    this->errorMessage = errorMessage;
}

Callisto::Framework::HoldStringException::HoldStringException(
    std::string&& errorMessage
)
{
    this->errorMessage = std::move(errorMessage);
}

#pragma endregion


#pragma region Methods

const char* Callisto::Framework::HoldStringException::what() const
{
    return this->errorMessage.c_str();
}

const std::string& Callisto::Framework::HoldStringException::GetMessage() const
{
    return this->errorMessage;
}

void Callisto::Framework::HoldStringException::MoveMessageTo(std::string& message)
{
    message = std::move(this->errorMessage);
}

#pragma endregion