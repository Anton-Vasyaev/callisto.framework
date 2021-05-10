cmake_minimum_required(VERSION 3.10)

project(callisto.framework)

set(TARGET_NAME callisto_framework)

option(CALLISTO_FRAMEWORK_SHARED "Build the shared library" OFF)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.runtime/executable)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.runtime/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.runtime/archive)

# set targets for callisto.framework
file(GLOB_RECURSE CALLISTO_FRAMEWORK_SRC "src/*.c" "src/*.cpp")

if(CALLISTO_FRAMEWORK_SHARED)
    set(LIBRARY_TYPE SHARED)
else()
    set(LIBRARY_TYPE STATIC)
endif()

include_directories(include)

add_library(${TARGET_NAME} ${LIBRARY_TYPE} ${CALLISTO_FRAMEWORK_SRC})
target_include_directories(${TARGET_NAME} PUBLIC include)
target_include_directories(${TARGET_NAME} PRIVATE src)

# TESTS AND MANUALS

# set targets for tests/manual/callisto.framework.show
if(NOT CONAN_CREATE)
    set(CALLISTO_FRAMEWORK_SHOW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests/manual/callisto.framework.show)
    include_directories(${CALLISTO_FRAMEWORK_SHOW_DIR})
    file(
        GLOB_RECURSE 
        CALLISTO_FRAMEWORK_SHOW_SRC
        "${CALLISTO_FRAMEWORK_SHOW_DIR}/src/*hpp"
        "${CALLISTO_FRAMEWORK_SHOW_DIR}/src/*.cpp"
        "${CALLISTO_FRAMEWORK_SHOW_DIR}/src/*.h" 
        "${CALLISTO_FRAMEWORK_SHOW_DIR}/src/*.c" 
    )
    add_executable(callisto_framework_show ${CALLISTO_FRAMEWORK_SHOW_SRC})
    target_include_directories(callisto_framework_show PRIVATE ${CALLISTO_FRAMEWORK_SHOW_DIR}/src)
endif()