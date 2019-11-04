//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_FRAMEWORK_API_DATA_H
#define CALLISTO_FRAMEWORK_API_DATA_H

#include <Callisto/Framework/Native/Types.h>


typedef struct
{
    void* data;
    t_size size;
} API_Buffer;

// STRING
typedef enum e_CodingType
{
    CodingType_ASCII,
    CodingType_UTF8,
    CodingType_UTF16,
    CodingType_UTF32,
	CodingType_Unknown
} CodingType;

typedef struct
{
	void* data;
    CodingType codingType;
    t_size size;
} API_String;

#endif