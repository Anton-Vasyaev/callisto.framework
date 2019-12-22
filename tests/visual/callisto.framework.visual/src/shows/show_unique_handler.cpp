// parent header
#include "show_declarations.hpp"
// test component
#include <callisto/framework/templates/unique_handler.hpp>
// std
#include <iostream>


struct disposable_struct
{
    int a;
    int b;
};

disposable_struct create_struct(int a, int b)
{
    return { a, b };
}

void dispose_struct(disposable_struct ob)
{
    std::cout << "obj before dispose (a:" << ob.a << ", b:" << ob.b << ")\n";
}

namespace callisto::framework
{
    template<>
    struct DefaultDisposer<disposable_struct>
    {
        void operator()(disposable_struct data)
        {
            dispose_struct(data);
        }
    };
}



void show_unique_handler()
{
    using namespace callisto::framework;

    auto handler_5_10 = UniqueScopeHandler<disposable_struct>(
        create_struct(5, 10)
    );
    auto handler_2_4 = UniqueScopeHandler<disposable_struct>(
        create_struct(2, 4)
    );

    std::cout << "Before set 2_4 in 5_10\n";
    handler_5_10 = std::move(handler_2_4);
    std::cout << "After set 2_4 in 5_10\n";
}