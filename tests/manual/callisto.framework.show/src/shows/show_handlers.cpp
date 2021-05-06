// parent header
#include "show_declarations.hpp"
// test component
#include <callisto/framework/templates/handlers.hpp>
// std
#include <iostream>


struct disposable_struct
{
    int a;
    int b;
};

disposable_struct create_struct(int a, int b)
{
    std::cout << "call create struct (a:" << a << ", b:" << b << ")\n";
    return { a, b };
}

void destroy_struct(disposable_struct ob)
{
    std::cout << "call destroy struct (a:" << ob.a << ", b:" << ob.b << ")\n";
}

namespace callisto::framework
{
    template<>
    struct default_disposer<disposable_struct>
    {
        void operator()(disposable_struct data)
        {
            destroy_struct(data);
        }
    };
}

void show_unique_handler()
{
    using namespace callisto::framework;

    auto handler_5_10 = unique_handler<disposable_struct>(
        create_struct(5, 10)
    );
    auto handler_2_4 = unique_handler<disposable_struct>(
        create_struct(2, 4)
    );

    std::cout << "Before set 2_4 in 5_10\n";
    handler_5_10 = std::move(handler_2_4);
    std::cout << "After set 2_4 in 5_10\n";
}

void show_shared_handler()
{
    using namespace callisto::framework;

    shared_handler<disposable_struct> handler_5_10_ref1;

    std::cout << "before scope\n";
    {
        std::cout << "create handler_5_10\n";
        auto handler_5_10 = shared_handler<disposable_struct>(
            create_struct(5, 10)
        );

        std::cout << "create handler_2_4\n";
        auto handler_2_4 = shared_handler<disposable_struct>(
            create_struct(2, 4)
        );

        std::cout << "get ref of handler_2_4\n";
        auto handler_2_4_ref1 = handler_2_4;

        std::cout << "get ref of handler_5_10\n";
        auto handler_5_10_ref2 = handler_5_10;

        std::cout << "get ref of handler_5_10\n";
        handler_5_10_ref1 = handler_5_10_ref2;
    }
    std::cout << "out of scope\n";
}

void show_handlers()
{
    std::cout << "Show UniqueHandler:\n";
    show_unique_handler();
    std::cout << "\nShow SharedHandler:\n";
    show_shared_handler();
}