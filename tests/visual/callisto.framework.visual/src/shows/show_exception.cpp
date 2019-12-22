//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <shows/show_declarations.hpp>
// test component
#include <callisto/framework/exception/hold_string_exception.hpp>
#include <callisto/framework/exception/detail_exception.hpp>
// std
#include <iostream>

using namespace callisto::framework;

void throw_holder_exception()
{
	std::string message = "Message in HoldStringException\n";
	throw HoldStringException(std::move(message));
}

void throw_detail_exception()
{
	std::string message = "Message in DetailException\n";
	THROW_DETAIL(message);
}

void show_exception()
{
	try 
	{ 
		throw_holder_exception();
	}
    catch(const std::exception& e)
    {
        std::cout << "Error:\n" << e.what() << std::endl;
    }

	try
	{
		throw_detail_exception();
	}
	catch (const std::exception & e)
	{
		std::cout << "Error:\n" << e.what() << std::endl;
	}
}