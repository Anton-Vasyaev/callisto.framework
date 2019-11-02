#ifndef CALLISTO_ENUMS_HPP
#define CALLISTO_ENUMS_HPP

namespace Callisto::Framework
{
    #pragma region MultiThreadAccessType

	enum MultiThreadAccessType
	{
		NoneLock,
		Atomic,
		Thread
	};

    #pragma endregion


    #pragma region AllocationType

    class StandartAllocation { };

    class AlignedAllocation { };

    #pragma endregion
}

#endif