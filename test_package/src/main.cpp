// test
//#include <callisto/framework/exception.hpp>
// std
#include <iostream>
// 3rd party
#include <gtest/gtest.h>

//namespace c_f = callisto::framework;

TEST(FooTest, MethodBarDoesAbc) {
    /*
    try
    {
        throw c_f::string_builder_exception("Int is ", 32, "bit");
    }
    catch(const c_f::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    */

    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}