#ifndef CALLISTO_FRAMEWORK_ENUMS_HPP
#define CALLISTO_FRAMEWORK_ENUMS_HPP

namespace callisto::framework
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