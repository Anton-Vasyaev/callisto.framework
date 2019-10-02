//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <Callisto/Exception/HoldStringException.hpp>


namespace Callisto::Framework
{
#pragma region ConstructAndDestruct

	HoldStringException::HoldStringException(
		std::string& errorMessage
	)
	{
		this->errorMessage = errorMessage;
	}

	HoldStringException::HoldStringException(
		std::string&& errorMessage
	)
	{
		this->errorMessage = std::move(errorMessage);
	}

	HoldStringException::HoldStringException(
		const char* errorMessage
	)
	{
		this->errorMessage = std::string(errorMessage);
	}

#pragma endregion


#pragma region Methods

	const char* HoldStringException::what() const
	{
		return this->errorMessage.c_str();
	}

	const std::string& HoldStringException::GetMessage() const
	{
		return this->errorMessage;
	}

	void HoldStringException::MoveMessageTo(std::string& message)
	{
		message = std::move(this->errorMessage);
	}

#pragma endregion
}