cmake_minimum_required(VERSION 3.10)

project(callisto.framework)

add_compile_definitions(SHARED=TRUE)

set(TARGET_NAME callisto_framework)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/runtime/executable)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/runtime/lib)


# set targets for callisto.framework
file(GLOB_RECURSE CALLISTO_FRAMEWORK_SRC "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.cpp" "src/*.h" "src/*.cpp")
include_directories(include)
include_directories(src)
add_library(${TARGET_NAME} ${CALLISTO_FRAMEWORK_SRC})


# TESTS AND MANUALS

# set targets for tests/manual/callisto.framework.show
set(CALLISTO_FRAMEWORK_SHOW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests/manual/callisto.framework.show)
include_directories(${CALLISTO_FRAMEWORK_SHOW_DIR})
file(
    GLOB_RECURSE 
    CALLISTO_FRAMEWORK_SHOW_SRC
    "${CALLISTO_FRAMEWORK_SHOW_DIR}/*hpp"
    "${CALLISTO_FRAMEWORK_SHOW_DIR}/*.cpp"
    "${CALLISTO_FRAMEWORK_SHOW_DIR}/*.h" 
    "${CALLISTO_FRAMEWORK_SHOW_DIR}/*.c" 
)
add_executable(callisto_framework_show ${CALLISTO_FRAMEWORK_SHOW_SRC})