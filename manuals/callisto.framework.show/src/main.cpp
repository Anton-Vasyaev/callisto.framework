// std
#include <iostream>
#include <chrono>
// solution
#include <callisto/framework/exception.hpp>
#include <callisto/framework/templates/signal.hpp>

namespace c_f = callisto::framework;
namespace chr = std::chrono;

void print(int a, int b)
{
    std::cout << "print:" << a << ":" << b << std::endl;
}

void print_2(int a, int b)
{
    std::cout << "print 2" << std::endl;
}

void print_3(int a, int b)
{
    std::cout << "print 3" << std::endl;
}

void raii_print(int a, int b)
{
    std::cout << "print raii" << std::endl;
}

int main()
{
    auto start = chr::high_resolution_clock::now();
    auto end   = chr::high_resolution_clock::now();

    c_f::signal<void(int, int)> signal;

    auto functor_print_2 = std::function(print_2);
    auto functor_print_3 = std::function(print_3);

    auto connection  = signal.connect(print);
    auto connection2 = signal.connect(functor_print_2);
    auto connection3 = signal.connect(std::move(functor_print_3));

    {
        std::cout << "before area\n";

        auto connection = signal.connect(raii_print).to_raii();

        signal(3, 4);

        std::cout << "after area\n";
    }

    std::cout << "disconnect\n";
    signal.disconnect(connection);

    signal(3, 4);
}