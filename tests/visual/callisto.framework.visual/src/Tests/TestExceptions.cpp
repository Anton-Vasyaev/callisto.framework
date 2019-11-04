//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <Tests/TestExceptions.hpp>
// test component
#include <Callisto/Framework/Exception/HoldStringException.hpp>
#include <Callisto/Framework/Exception/DetailException.hpp>
// std
#include <iostream>

using namespace Callisto::Framework;

void throwHolderException()
{
	std::string message = "Message in HoldStringException\n";
	throw HoldStringException(std::move(message));
}

void throwDetailException()
{
	std::string message = "Message in DetailException\n";
	THROW_DETAIL(message);
}

void test_exceptions()
{
	try 
	{ 
		throwHolderException();
	}
    catch(const std::exception& e)
    {
        std::cout << "Error:\n" << e.what() << std::endl;
    }

	try
	{
		throwDetailException();
	}
	catch (const std::exception & e)
	{
		std::cout << "Error:\n" << e.what() << std::endl;
	}
}