cmake_minimum_required(VERSION 3.10)

option(SHARED_LIB "Build the shared library" ON)

project(callisto.framework)
set(PROJECT_NAME "callisto.framework")


include(../submodules/callisto.configure/CallistoConfigure.cmake)

#-------------------------------------------------------------------------------------------------#
#---------------------------------------PROJECT PROPERTIES----------------------------------------#
#-------------------------------------------------------------------------------------------------#
# SET PROPERTIES FOR C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# SET OUTPUT
set(
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY 
	${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/archive
)
set(
	CMAKE_LIBRARY_OUTPUT_DIRECTORY 
	${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/library
)
set(
	CMAKE_RUNTIME_OUTPUT_DIRECTORY 
	${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/dll
)
# SET VARIABLE
set(LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3rd party
if(UNIX)
	find_package(Threads REQUIRED)
endif()
include(../packages/Conan_${CALLISTO_BIT_DESIGN}/${CALLISTO_BUILD_TYPE}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)

# LIB PART
file(GLOB_RECURSE lib_source_list "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.h" "src/*.cpp")

#-------------------------------------------------------------------------------------------------#
#-----------------------------MAKE PATH AND NAME FOR BUILD RESULT---------------------------------#
#-------------------------------------------------------------------------------------------------#

# SET DEPENDENCIES (*.dll, *.xml and other files that should be in the directory)
set(LIB_DEPENDENCIES "")

# CONFIGURE LIBRARY NAME
set(LIB_NAME "callisto_framework_${CALLISTO_BIT_DESIGN}${CALLISTO_BUILD_TYPE_POSTFIX}")
if(SHARED_LIB)
	add_library(${LIB_NAME} SHARED ${lib_source_list})
	string(
		CONCAT SHARED_LIB_PATH 
		"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/"
		"${LIB_NAME}."
		"${CALLISTO_SHARED_LIB_EXT_NAME}"
	)
	list(APPEND LIB_DEPENDENCIES ${SHARED_LIB_PATH})
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

target_link_libraries(${LIB_NAME} ${CONAN_LIBS})

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