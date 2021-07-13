// test
#include <callisto/framework/exception.hpp>
// 3rd party
#include <gtest/gtest.h>

namespace c_f = callisto::framework;

TEST(exceptions, string_builder_exception_1) {
    std::string bit_message       = "bit";
    std::string exception_message = "";
    try
    {
        throw c_f::string_builder_exception(
            "Int32", " ", "is", " not ", 64, bit_message 
        );
    }
    catch(const c_f::exception& e)
    {
        exception_message = e.what();
    }
    
    ASSERT_EQ(exception_message, "Int32 is not 64bit");
}

TEST(exceptions, test_wstring_holder_exception_1) {
    std::wstring bit_message       = L"bit";
    std::wstring exception_message = L"";
    try
    {
        throw c_f::wstring_builder_exception(
            "Int32", " ", "is", " not ", 64, bit_message 
        );
    }
    catch(const c_f::wexception& e)
    {
        exception_message = e.what();
    }
    
    ASSERT_EQ(exception_message, L"Int32 is not 64bit");
}
