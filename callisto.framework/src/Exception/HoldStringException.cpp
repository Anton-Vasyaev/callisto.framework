//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <Callisto/Framework/Exception/HoldStringException.hpp>


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

	const std::string& HoldStringException::GetErrorMessage() const
	{
		return this->errorMessage;
	}

	void HoldStringException::MoveMessageTo(std::string& message)
	{
		message = std::move(this->errorMessage);
	}

#pragma endregion


	void throw_hold_string()
	{
		auto message = std::string("throw from callisto.framework");
		throw HoldStringException(std::move(message));
	}
}