#!/bin/bash
# init
function pause(){
   read -p "$*"
}

mkdir packages
cd packages

#for x64 SYSTEM
mkdir Conan_x64
cd Conan_x64

#----For Debug
mkdir Debug
cd Debug
conan install ../../.. -s build_type=Debug -s arch=x86_64

cd ..

#----For Release
mkdir Release
cd Release
conan install ../../.. -s build_type=Release -s arch=x86_64

cd ../..

#for x32 SYSTEM
mkdir Conan_x32
cd Conan_x32

#----For Debug
mkdir Debug
cd Debug
conan install ../../.. -s build_type=Debug -s arch=x86

cd ..

#----For Release
mkdir Release
cd Release
conan install ../../.. -s build_type=Release -s arch=x86

cd ../../..
pause 'press [Any] key to continue'