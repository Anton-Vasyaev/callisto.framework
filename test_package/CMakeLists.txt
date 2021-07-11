cmake_minimum_required(VERSION 3.19)

project(callisto.framework.test)
set(TARGET_NAME callisto_framework_auto)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 20)

# set targets for callisto.framework
file(GLOB_RECURSE AUTO_SRC "src/*.c" "src/*.cpp")

add_executable(${TARGET_NAME} ${AUTO_SRC})