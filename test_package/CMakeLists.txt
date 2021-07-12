cmake_minimum_required(VERSION 3.19)

project(callisto.framework.test CXX)
set(TARGET_NAME callisto_framework_auto)

# for conan
if(DEFINED CREATE_PACKAGE)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    CONAN_BASIC_SETUP()
endif()

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

file(GLOB_RECURSE AUTO_SRC "src/*.c" "src/*.cpp")
add_executable(${TARGET_NAME} ${AUTO_SRC})

# for conan
if(DEFINED CREATE_PACKAGE) 
    message("CONAN LIBS:${CONAN_LIBS}")
    target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})
    target_include_directories(${TARGET_NAME} PRIVATE ${CONAN_INCLUDE_DIRS})
# for manual testing
else()
    # link with callisto.framework
    add_subdirectory(${CMAKE_SOURCE_DIR}/../callisto.framework ${CMAKE_CURRENT_BINARY_DIR}/callisto.framework)
    target_link_libraries(${TARGET_NAME} callisto_framework)
    add_custom_command(
        TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} 
        -E copy_if_different 
        $<TARGET_FILE:callisto_framework> 
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )

    # link with conan libraries
    set(CONAN_RUNTIME_DIR ${CMAKE_SOURCE_DIR}/../.runtime/conan/x64/${CMAKE_BUILD_TYPE})
    list(APPEND CMAKE_MODULE_PATH ${CONAN_RUNTIME_DIR})
    
    find_package(GTest)
    target_link_libraries(${TARGET_NAME} GTest::GTest)

    file(GLOB BINARY_SHARED_LIBRARIES "${CONAN_RUNTIME_DIR}/bin/*.dll")
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