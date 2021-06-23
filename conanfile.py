from conans import ConanFile, CMake, tools

class CallistoFrameworkConan(ConanFile):
    name = "callisto.framework"
    version = "0.1.0"
    license = "BSD"
    settings = "os", "compiler", "build_type", "arch"

    exports = "*"

    options = { 
        "shared" : [True, False]
    }
    default_options = {
        "shared" : False
    }
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CALLISTO_FRAMEWORK_SHARED"] = self.options.shared
        cmake.configure()
        cmake.build()

    
    def package_info(self):
        self.cpp_info.includedirs = [ "include" ]
        self.cpp_info.libs = [ "callisto_framework" ]
