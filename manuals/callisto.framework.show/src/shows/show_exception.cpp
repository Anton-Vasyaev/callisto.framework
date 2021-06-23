//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include "show_declarations.hpp"
// test component
#include <callisto/framework/exception.hpp>
// std
#include <iostream>

namespace c_f = callisto::framework;

void throw_holder_exception()
{
	std::string message = "message in string_holder_exception\n";
	throw c_f::string_holder_exception(std::move(message));
}

void throw_builder_exception()
{
	std::string name = "Andrew";
	throw c_f::string_builder_exception(
		"5 is ", 5, ", but 2 is ", 2, ". My name is ", name 
	);
}

void show_exception()
{
	try 
	{ 
		throw_holder_exception();
	}
    catch(const c_f::exception& e)
    {
        std::cout << "Error:\n" << e.what() << std::endl;
    }

	try
	{
		throw_builder_exception();
	}
	catch (const c_f::exception & e)
	{
		std::cout << "Error:\n" << e.what() << std::endl;
	}
}