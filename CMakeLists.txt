cmake_minimum_required(VERSION 3.10)

project(callisto.framework)

#-------------------------------------------------------------------------------------------------#
#---------------------------------------PROJECT PROPERTIES----------------------------------------#
#-------------------------------------------------------------------------------------------------#
SET(SHARED_LIB TRUE)

#-------------------------------------------------------------------------------------------------#
#--------------------------------------------CONFIGURE--------------------------------------------#
#-------------------------------------------------------------------------------------------------#

# SET PROPERTIES FOR C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# DETECT BIT DESIGN
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(BIT_DESIGN "x64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(BIT_DESIGN "x32")
else()
	message(FATAL_ERROR "Not have project configuration for bit design:${CMAKE_SIZEOF_VOID_P}-byte")
endif()

# DETECT BUILD TYPE (Debug/Release)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
	set(BUILD_TYPE "Debug")
else()
	set(BUILD_TYPE "Release")
endif()

# DETECT OS
if(WIN32)
	set(OS_NAME "Win")
elseif(LINUX)
	set(OS_NAME "Linux")
else()
	message(FATAL_ERROR "Not have project configuration for os:${OS_NAME}")
endif()

# SET OUTPUT
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output_files/${OS_NAME}/${BIT_DESIGN}/${BUILD_TYPE}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output_files/${OS_NAME}/${BIT_DESIGN}/${BUILD_TYPE}/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output_files/${OS_NAME}/${BIT_DESIGN}/${BUILD_TYPE}/binary)

# SET VARIABLE
set(CALLISTO_FRAMEWORK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(UNIX)
	find_package(Threads REQUIRED)
endif()

include_directories(include)

# LIB PART
file(GLOB_RECURSE lib_source_list "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.h" "src/*.cpp")

add_library(callisto_framework STATIC ${lib_source_list})
