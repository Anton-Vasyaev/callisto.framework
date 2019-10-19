cmake_minimum_required(VERSION 3.10)

project(callisto.framework.visual_test)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ ${CAMEK_CURRENT_SOURCE_DIR}/CALLISTO_FRAMEWORK)

#-------------------------------------------------------------------------------------------------#
#--------------------------------------------CONFIGURE--------------------------------------------#
#-------------------------------------------------------------------------------------------------#

# SET PROPERTIES FOR C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("callisto headers:${CALLISTO_FRAMEWORK_INCLUDE_DIR}")
# DETECT BIT DESIGN
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(CALLISTO_BIT_DESIGN "x64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(CALLISTO_BIT_DESIGN "x32")
else()
	message(FATAL_ERROR "Not have project configuration for bit design:${CMAKE_SIZEOF_VOID_P}-byte")
endif()

# DETECT BUILD TYPE (Debug/Release)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
	set(CALLISTO_BUILD_TYPE "Debug")
else()
	set(CALLISTO_BUILD_TYPE "Release")
endif()

# DETECT OS
SET(CALLISTO_OS_NAME ${CMAKE_SYSTEM_NAME})

if(CALLISTO_OS_NAME MATCHES "Windows")
elseif(CALLISTO_OS_NAME MATCHES "Linux")
else()
	message(FATAL_ERROR "Not have project configuration for os:${OS_NAME}")
endif()




# SET OUTPUT
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output_files/${CALLISTO_OS_NAME}/${CALLISTO_BIT_DESIGN}/${CALLISTO_BUILD_TYPE}/binary)

set(visual_test_headers src)
file(GLOB_RECURSE visual_test_sources "src/*.cpp")

include_directories(${CALLISTO_FRAMEWORK_INCLUDE_DIR})

message("callisto headers:${CALLISTO_FRAMEWORK_INCLUDE_DIR}")
add_executable(framework_visual_test ${visual_test_sources})
target_include_directories(framework_visual_test PRIVATE ${visual_test_headers})

target_link_libraries(framework_visual_test ${CALLISTO_FRAMEWORK_LIBNAME})

target_link_libraries (framework_visual_test ${CMAKE_THREAD_LIBS_INIT})
