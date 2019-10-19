cmake_minimum_required(VERSION 3.10)

project(callisto.framework)


#-------------------------------------------------------------------------------------------------#
#---------------------------------------PROJECT PROPERTIES----------------------------------------#
#-------------------------------------------------------------------------------------------------#
SET(CALLISTO_FRAMEWORK_SHARED TRUE)

# SET OUTPUT
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/dll)

# SET VARIABLE
set(CALLISTO_FRAMEWORK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

if(UNIX)
	find_package(Threads REQUIRED)
endif()

include_directories(include)

message("STANDART:${CMAKE_CXX_STANDARD}")

# LIB PART
file(GLOB_RECURSE lib_source_list "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.h" "src/*.cpp")

# CONFIGURE LIBRARY NAME
set(CALLISTO_FRAMEWORK_LIBNAME "callisto_framework_${BIT_DESIGN}${BUILD_TYPE_POSTFIX}" PARENT_SCOPE)


if(CALLISTO_FRAMEWORK_SHARED)
	add_library(${CALLISTO_FRAMEWORK_LIBNAME} SHARED ${lib_source_list})
	set(
		CALLISTO_FRAMEWORK_SHARED_LIB_PATH 
		${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
		${CALLISTO_FRAMEWORK_LIBNAME}.
		${CALLISTO_SHARED_LIB_EXT_NAME} PARENT_SCOPE
	)
else()
	set(CALLISTO_FRAMEWORK_LIBNAME "${CALLISTO_FRAMEWORK_LIBNAME}s")
	add_library(${CALLISTO_FRAMEWORK_LIBNAME} STATIC ${lib_source_list})
endif()

set(
	CALLISTO_FRAMEWORK_LIB_PATH 
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/
	${CALLISTO_FRAMEWORK_LIB_NAME}.
	${CALLISTO_STATIC_LIB_EXT_NAME} PARENT_SCOPE
)
