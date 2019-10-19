//
// Copyright (c) 2019
// Vasyaev Anton
//

#ifndef CALLISTO_FRAMEWORK_TEST_EXCEPTIONS_HPP
#define CALLISTO_FRAMEWORK_TEST_EXCEPTIONS_HPP

// test component
#include <Callisto/Framework/Exception/HoldStringException.hpp>
// std
#include <iostream>



using namespace Callisto::Framework;

void test_exceptions()
{
    try
    {
        std::string message = "TEST THROW";
        throw HoldStringException(std::move(message));
        //throw std::runtime_error("message runtime");
    }
    catch(const std::exception& e)
    {
        std::cout << "Error:" << e.what() << std::endl;
    }
    
}

#endif