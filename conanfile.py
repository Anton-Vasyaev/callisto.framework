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
        cmake.definitions["CREATE_PACKAGE"] = "1"
        cmake.configure()
        cmake.build()


    def package(self):
        self.copy("*.h",   dst="include", src="include")
        self.copy("*.hpp", dst="include", src="include")

        self.copy("*.lib",   dst="lib", keep_path=False)
        self.copy("*.a",     dst="lib", keep_path=False)
        self.copy("*.dll",   dst="bin", keep_path=False)
        self.copy("*.so",    dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
    

    def package_info(self):
        self.cpp_info.libs = [ "callisto_framework" ]
