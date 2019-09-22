cmake_minimum_required(VERSION 3.10)

project(callisto.framework)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")

find_package(Threads REQUIRED)

include_directories(include)

file(GLOB_RECURSE visual_test_source_list "visual_test/*.cpp" "visual_test/.h")

add_executable(framework_visual_test ${visual_test_source_list})
target_include_directories(framework_visual_test PRIVATE visual_test)
target_link_libraries (framework_visual_test ${CMAKE_THREAD_LIBS_INIT})