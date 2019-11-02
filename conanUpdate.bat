mkdir packages
cd packages

REM for x64 SYSTEM
mkdir Conan_x64
cd Conan_x64

REM ----For Debug
mkdir Debug
cd Debug
conan install ../../.. -s build_type=Debug -s arch=x86_64

cd ..

REM ----For Release
mkdir Release
cd Release
conan install ../../.. -s build_type=Release -s arch=x86_64

cd ../..

REM for x32 SYSTEM
mkdir Conan_x32
cd Conan_x32

REM ----For Debug
mkdir Debug
cd Debug
conan install ../../.. -s build_type=Debug -s arch=x86

cd ..

REM ----For Release
mkdir Release
cd Release
conan install ../../.. -s build_type=Release -s arch=x86

cd ../../..
pause