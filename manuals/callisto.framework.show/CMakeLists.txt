cmake_minimum_required(VERSION 3.19)

# configure project *******************************************************************************
project(callisto.framework_show)
set(TARGET_NAME callisto_framework_show)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD     20)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# collect source and linked libraries to executable file ******************************************
file(GLOB_RECURSE CALLISTO_FRAMEWORK_SHOW_SRC "src/*.c" "src/*.cpp")
add_executable(${TARGET_NAME} ${CALLISTO_FRAMEWORK_SHOW_SRC})
target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})

# link with callisto.framework ********************************************************************
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/../../callisto.framework 
    ${CMAKE_CURRENT_BINARY_DIR}/callisto.framework
)
target_link_libraries(${TARGET_NAME} callisto_framework)

# copy dlls if platform is windows ****************************************************************
if(WIN32)
    add_custom_command(
        TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} 
        -E copy_if_different 
        $<TARGET_FILE:callisto_framework> 
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endif()