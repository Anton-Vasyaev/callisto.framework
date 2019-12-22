//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <callisto/framework/exception/hold_string_exception.hpp>


using namespace callisto::framework;

#pragma region ConstructAndDestruct

HoldStringException::HoldStringException(
	std::string& error_message
)
{
	this->error_message = error_message;
}

HoldStringException::HoldStringException(
	std::string&& error_message
)
{
	this->error_message = std::move(error_message);
}

HoldStringException::HoldStringException(
	const char* error_message
)
{
	this->error_message = std::string(error_message);
}

#pragma endregion


#pragma region Methods

const char* HoldStringException::what() const noexcept
{
	return this->error_message.c_str();
}

const std::string& HoldStringException::get_error_message() const
{
	return this->error_message;
}

void HoldStringException::move_message_to(
	std::string& message
)
{
	message = std::move(this->error_message);
}

#pragma endregion