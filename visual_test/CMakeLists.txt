cmake_minimum_required(VERSION 3.10)

project(callisto.framework.visual_test)

include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)

# SET OUTPUT
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output_files/${OS_NAME}/${BIT_DESIGN}/${BUILD_TYPE}/binary)

file(GLOB_RECURSE visual_test_source_list "src/*.cpp" "src/*.h" "src/*.hpp:")

include_directories(${CALLISTO_FRAMEWORK_INCLUDE_DIR})

add_executable(framework_visual_test ${visual_test_source_list})
target_link_libraries(framework_visual_test callisto_framework)

target_include_directories(framework_visual_test PRIVATE src)
target_link_libraries (framework_visual_test ${CMAKE_THREAD_LIBS_INIT})

message("include dir:${CALLISTO_FRAMEWORK_INCLUDE_DIR}")