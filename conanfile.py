from conans import ConanFile, CMake, tools

class CallistoFrameworkConan(ConanFile):
    name = "callisto.framework"
    version = "0.1.0"
    license = "BSD"
    settings = "os", "compiler", "build_type", "arch"
    options = { 
        "shared" : [True, False]
    }
    default_options = {
        "shared" : False
    }
    generators = "cmake"

    def source(self):
        import os

        tools.replace_in_file(
            "CMakeLists.txt",
            "project(callisto.framework)",
            '''
            project(callisto.framework)
            set(PACKAGE_CREATE TRUE)
            '''
        )

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CALLISTO_FRAMEWORK_SHARED"] = self.options.shared
        cmake.configure(build_dir="./")
        
        cmake.build()


    def package(self):
        pass

    
    def package(self):
        self.cpp_info.libs = [ "callisto_framework" ]
