//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_FRAMEWORK_API_STRING_HPP
#define CALLISTO_FRAMEWORK_API_STRING_HPP

// std
#include <iostream>
#include <string>
#include <string_view>
// project
#include <callisto/framework/native/lib_export.h>
#include <callisto/framework/native/api/api_data.h>


namespace callisto::framework
{
	CALLISTO_EXPORT std::string CALLISTO_CALL get_string(API_String str);

	CALLISTO_EXPORT std::string_view CALLISTO_CALL get_string_view(API_String str);
}

#endif