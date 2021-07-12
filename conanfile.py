from conans import ConanFile, CMake, tools

class CallistoFrameworkConan(ConanFile):
    name       = 'callisto.framework'
    version    = '0.1.0'
    license    = 'BSD'
    settings   = 'os', 'compiler', 'build_type', 'arch'
    generators = 'cmake'
    exports    = '*'

    options = { 
        'shared' : [True, False]
    }
    default_options = {
        'shared' : False
    }


    def build(self):
        cmake = CMake(self)
        cmake.definitions['CALLISTO_FRAMEWORK_SHARED'] = self.options.shared
        cmake.definitions['CREATE_PACKAGE'] = "1"
        cmake.configure(source_folder='callisto.framework')
        cmake.build()


    def package(self):
        self.copy('*.h',   dst='include', src='callisto.framework/include')
        self.copy('*.hpp', dst='include', src='callisto.framework/include')

        self.copy('*callisto_framework.lib',   dst='lib', keep_path=False)
        self.copy('*callisto_framework.a',     dst='lib', keep_path=False)
        self.copy('*callisto_framework.dll',   dst='bin', keep_path=False)
        self.copy('*callisto_framework.so',    dst='lib', keep_path=False)
        self.copy('*callisto_framework.dylib', dst='lib', keep_path=False)
    

    def package_info(self):
        self.cpp_info.libs = [ 'callisto_framework' ]