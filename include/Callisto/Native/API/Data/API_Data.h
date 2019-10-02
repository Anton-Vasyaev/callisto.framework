//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CALLISTO_FRAMEWORK_API_DATA_H
#define CALLISTO_FRAMEWORK_API_DATA_H

#include <Callisto/Native/Types.h>


typedef struct
{
    void* data;
    t_size size;
} API_Buffer;

// STRING
typedef enum Coding
{
    Coding_ASCII,
    Coding_UTF8,
    Coding_UTF16,
    Coding_UTF32,
	Coding_Unknown
};

typedef struct
{
	void* data;
    Coding coding;
    t_size size;
} API_String;

#endif