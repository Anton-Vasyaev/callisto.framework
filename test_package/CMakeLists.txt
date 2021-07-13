cmake_minimum_required(VERSION 3.19)

# configure project *******************************************************************************
project(callisto.framework.test CXX)
set(TARGET_NAME callisto_framework_auto)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD     20)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# conan settings **********************************************************************************
set(CONAN_DIR "")
if(DEFINED CREATE_PACKAGE)
    set(CONAN_DIR ${CMAKE_BINARY_DIR})
else()
    set(CONAN_DIR ${CMAKE_SOURCE_DIR}/../.runtime/conan/x64/${CMAKE_BUILD_TYPE})
endif()
include(${CONAN_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# collect source and linked libraries to executable file ******************************************
file(GLOB_RECURSE AUTO_SRC "src/*.c" "src/*.cpp")
add_executable(${TARGET_NAME} ${AUTO_SRC})
target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})

# link with callisto.framework for custom testing *************************************************
if(NOT DEFINED CREATE_PACKAGE)
    add_subdirectory(
        ${CMAKE_SOURCE_DIR}/../callisto.framework 
        ${CMAKE_CURRENT_BINARY_DIR}/callisto.framework
    )
    target_link_libraries(${TARGET_NAME} callisto_framework)
    # copy dlls if platform is windows
    if(WIN32)
        add_custom_command(
            TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} 
            -E copy_if_different 
            $<TARGET_FILE:callisto_framework> 
            $<TARGET_FILE_DIR:${TARGET_NAME}>
        )
    endif()
endif()

# copy dlls if platform is windows ****************************************************************
if(WIN32)
    file(GLOB BINARY_SHARED_LIBRARIES "${CONAN_DIR}/bin/*.dll")
    foreach(BINARY_SHARED_LIBRARY IN LISTS BINARY_SHARED_LIBRARIES)
        add_custom_command(
            TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} 
            -E copy_if_different 
            ${BINARY_SHARED_LIBRARY}
            $<TARGET_FILE_DIR:${TARGET_NAME}>
        )
    endforeach()
endif()