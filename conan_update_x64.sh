#!/bin/bash

current_directory=$(pwd)
conan_dir="${current_directory}/.runtime/conan"
echo ${conan_dir}

conan install conanfile.txt -if ${conan_dir}/x64/Debug   -s build_type=Debug   -s arch=x86_64 --build=missing
conan install conanfile.txt -if ${conan_dir}/x64/Release -s build_type=Release -s arch=x86_64 --build=missing