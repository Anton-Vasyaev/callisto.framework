# python
import os
# 3rd party
from conans import ConanFile, CMake, tools


class TestConanCallistoFramework(ConanFile):
    name = "TestConanCallistoFramework"

    settings   = "os", "compiler", "arch", "build_type"
    generators = "cmake"

    requires        = "gtest/1.8.1"
    default_options = "gtest:shared=True"

    def build(self):
        self.cmake = CMake(self)
        self.cmake.definitions["CREATE_PACKAGE"] = "1"
        self.cmake.configure()
        self.cmake.build()


    def imports(self):
        self.copy("*.so", "bin", "lib")
        self.copy("*.dll", "bin", "bin")
        self.copy("*.dylib", "bin", "lib")


    def test(self):
        if not tools.cross_building(self.settings):
            bin_path = os.path.join("bin", "callisto_framework_auto")
            self.run(bin_path, run_environment=True)
