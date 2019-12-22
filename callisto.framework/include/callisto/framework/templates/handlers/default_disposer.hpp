#ifndef CALLISTO_FRAMEWORK_DEFAULT_DISPOSER_HPP
#define CALLISTO_FRAMEWORK_DEFAULT_DISPOSER_HPP

namespace callisto::framework
{
    template<typename Type>
    struct DefaultDisposer
    {
        void operator()(Type data);
    };
}

#endif