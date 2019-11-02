cmake_minimum_required(VERSION 3.10)

option(SHARED_LIB "Build the shared library" ON)

project(callisto.framework)

include(../submodules/callisto.configure/CallistoConfigure.cmake)

#-------------------------------------------------------------------------------------------------#
#---------------------------------------PROJECT PROPERTIES----------------------------------------#
#-------------------------------------------------------------------------------------------------#
# C++ properties
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 3rd party
if(UNIX)
	find_package(Threads REQUIRED)
endif()
include(../packages/Conan_${CALLISTO_BIT_DESIGN}/${CALLISTO_BUILD_TYPE}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)
# include "include dirs"
include_directories(include)
set(LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Set output
set(ARCHIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/archive)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/lib)
set(DLL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/dll)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DLL_DIR})
message("OUTPUT DIR:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
# Find sources
file(GLOB_RECURSE lib_source_list "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.h" "src/*.cpp")


#-------------------------------------------------------------------------------------------------#
#-----------------------------MAKE PATH AND NAME FOR BUILD RESULT---------------------------------#
#-------------------------------------------------------------------------------------------------#
# Set dependencies (*.dll, *.xml and other files that should be in the directory)
set(LIB_DEPENDENCIES "")

# Configure library name
set(LIB_NAME "callisto_framework_${CALLISTO_BIT_DESIGN}${CALLISTO_BUILD_TYPE_POSTFIX}")
if(SHARED_LIB)
	add_library(${LIB_NAME} SHARED ${lib_source_list})
	string(
		CONCAT SHARED_LIB_PATH 
		"${PROJECT_SOURCE_DIR}/"
		"build_result/${CALLISTO_BUILD_PATH}/dll/"
		"${LIB_NAME}."
		"${CALLISTO_SHARED_LIB_EXT_NAME}"
	)
	list(APPEND LIB_DEPENDENCIES ${SHARED_LIB_PATH})
	message("SHAR LIB PAH:${SHARED_LIB_PATH}")
else()
	set(LIB_NAME "${LIB_NAME}s")
	add_library(${LIB_NAME} STATIC ${lib_source_list})
endif()

string(
	CONCAT LIB_PATH 
	"${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/"
	"${LIB_NAME}."
	"${CALLISTO_STATIC_LIB_EXT_NAME}"
)
# postbuild actions
install(
	DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
	DESTINATION ${PROJECT_SOURCE_DIR}/build_result
)

#-------------------------------------------------------------------------------------------------#
#------------------------------------VARIABLES FOR PARENT SCOPE-----------------------------------#
#-------------------------------------------------------------------------------------------------#
set(CALLISTO_FRAMEWORK_SHARED ${SHARED} CACHE INTERNAL "" FORCE)

# path to shared and static lib
set(CALLISTO_FRAMEWORK_LIB_INCLUDE_DIR ${LIB_INCLUDE_DIR} CACHE INTERNAL "" FORCE)
set(CALLISTO_FRAMEWORK_SHARED_LIB_PATH ${SHARED_LIB_PATH} CACHE INTERNAL "" FORCE)
set(CALLISTO_FRAMEWORK_LIB_PATH ${LIB_PATH} CACHE INTERNAL "" FORCE)

# path to dependencies
set(CALLISTO_FRAMEWORK_DEPENDENCIES ${LIB_DEPENDENCIES} CACHE INTERNAL "" FORCE)

message("FRAMEWORK DEPENDENCIES:${PROJECT_SOURCE_DIR}")
message("PROJECT DIR:${PROJECT_SOURCE_DIR}")
message("OUTPUT DIR:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")