cmake_minimum_required(VERSION 3.19)

# configure project *******************************************************************************
project(callisto.framework)
set(TARGET_NAME callisto_framework)

option(CALLISTO_FRAMEWORK_SHARED "Build the shared library" OFF)

set(CMAKE_CXX_STANDARD 20)

if(CALLISTO_FRAMEWORK_SHARED)
    set(LIBRARY_TYPE SHARED)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    set(LIBRARY_TYPE STATIC)
endif()

# collects source to target ***********************************************************************
file(GLOB_RECURSE CALLISTO_FRAMEWORK_SRC "src/*.c" "src/*.cpp")
add_library(${TARGET_NAME} ${LIBRARY_TYPE} ${CALLISTO_FRAMEWORK_SRC})

target_include_directories(${TARGET_NAME} PUBLIC  include)
target_include_directories(${TARGET_NAME} PRIVATE src)