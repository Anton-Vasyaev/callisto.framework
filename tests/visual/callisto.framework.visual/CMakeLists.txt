cmake_minimum_required(VERSION 3.10)

project(callisto.framework.visual_test)

add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/../../../callisto.framework 
	${CMAKE_CURRENT_SOURCE_DIR}/build/subproject/CALLISTO_FRAMEWORK)

#-------------------------------------------------------------------------------------------------#
#--------------------------------------------CONFIGURE--------------------------------------------#
#-------------------------------------------------------------------------------------------------#
# C++ properties
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build_result/${CALLISTO_BUILD_PATH}/binary)

include_directories(src)
file(GLOB_RECURSE visual_test_sources "src/*.cpp" "src/*.hpp" "src/*.h")

set(OUTPUT_NAME "callisto_framework_visual")
add_executable(${OUTPUT_NAME} ${visual_test_sources})

#-------------------------------------------------------------------------------------------------#
#-------------------------------------------DEPENDENCIES------------------------------------------#
#-------------------------------------------------------------------------------------------------#
# headers
include_directories(${CALLISTO_FRAMEWORK_LIB_INCLUDE_DIR})
# static link 
target_link_libraries(${OUTPUT_NAME} ${CALLISTO_FRAMEWORK_LIB_PATH})
# dependencies
file(
	COPY ${CALLISTO_FRAMEWORK_DEPENDENCIES}
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)