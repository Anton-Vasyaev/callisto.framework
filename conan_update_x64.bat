set current_path=%cd%


set conan_dir=%current_path%\.runtime\conan


conan install conanfile.txt -if %conan_dir%\x64\Debug   -s build_type=Debug   -s arch=x86_64 --build=missing
conan install conanfile.txt -if %conan_dir%\x64\Release -s build_type=Release -s arch=x86_64 --build=missing