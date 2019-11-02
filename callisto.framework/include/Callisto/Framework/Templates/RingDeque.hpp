//
// Copyright (c) 2019
// Vasyaev Anton
//

#ifndef CALLISTO_RING_DEQUE_HPP
#define CALLISTO_RING_DEQUE_HPP

// std
#include <memory>
#include <stdexcept>
#include <mutex>
#include <atomic>
// project
#include <Callisto/Native/Types.h>
#include <Callisto/Auxiliary/Enums.hpp>



namespace Callisto::Framework
{
	template<
		class T,
		class AccessType = NoneLock
	>
    class RingDeque
    {
    protected:
	#pragma region Data

			std::mutex _locker;
			
            std::unique_ptr<T> _data;
            t_size _size;
            t_size _tail;
            t_size _start;
            t_size _count;

            #pragma endregion

            #pragma region PrivateMethods

            inline t_size DistanceBetweenStartAndTail()
            {
                auto allocSize = _size + (t_size)1;
                if(_start == _tail) return 0;
                if(_start >= _tail)
                {
                    if(_start - _tail == 1) return _size;
                    
                    auto startToEnd = allocSize - _start;
                    return startToEnd + _tail;
                }
                else return _tail - _start;
            }

            #pragma endregion
        public:
            #pragma region Usings

            using AccessType = AccessType;

            using Type = T;

            #pragma endregion


            #pragma region ConstructAndDestruct

            RingDeque() = delete;

            RingDeque(t_size size) 
            {
                if(size <= 2) throw std::invalid_argument(
                    "pass size of ring deque <= 2"
                );

                auto allocSize = size + (t_size)1;
                _data = std::unique_ptr<T[]>(allocSize);
                _tail = 0;
                _start = 0;
                _count = 0;
                _size = size;
            }

            RingDeque(RingDeque<T>& ringDeque)
            {
                auto allocSize = ringDeque._size + (t_size)1;
                _data = std::unique_ptr<T[]>(allocSize);

                std::copy(_data.get(), ringDeque._data.get(), allocSize);
                _size = ringDeque._size;
                _start = ringDeque._start;
                _tail = ringDeque._tail;
                _count = ringDeque._count;
            }

            #pragma endregion


            #pragma region PublicMethods

            bool PushBack(T value) 
            {
                auto pushStatus = false;
                if(_tail == )
            }

            void Clear()
            {
                _start = 0;
                _tail = 0;
                _count = 0;
            }

            #pragma endregion
        };

}

#endif