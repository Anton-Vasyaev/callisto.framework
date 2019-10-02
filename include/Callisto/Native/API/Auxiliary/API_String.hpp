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
#include <Callisto/Native/LibExport.h>
#include <Callisto/Native/API/Data/API_Data.h>



namespace Callisto::Framework
{
	CALLISTO_EXPORT std::string CALLISTO_CALL getString(API_String str);

	CALLISTO_EXPORT std::string_view CALLISTO_CALL getStringView(API_String str);
}

#endif