#ifndef CALLISTO_ENUMS_HPP
#define CALLISTO_ENUMS_HPP

namespace Callisto
{
    #pragma region MultiThreadAccessType

    class NoneLock { };

    class ThreadLock { };

    class AtomicLock { };

    #pragma endregion


    #pragma region AllocationType

    class StandartAllocation { };

    class AlignedAllocation { };

    #pragma endregion
}

#endif