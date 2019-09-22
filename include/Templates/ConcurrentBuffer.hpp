//
// Copyright (c) 2019
// Vasyaev Anton
//
#ifndef CONCURRENT_BUFFER_HPP
#define CONCURRENT_BUFFER_HPP

// std
#include <deque>
#include <mutex>



template<typename B>
class ConcurrentBuffer
{
private:
	// data
	size_t _bufferCapacity;
	std::deque<B> _buffer;
	std::mutex _locker;

public:
	#pragma region ConstructAndDestruct

	ConcurrentBuffer() : ConcurrentBuffer(128)
	{
	}

	ConcurrentBuffer(size_t bufferCapacity)
	{
		_bufferCapacity = bufferCapacity;
		_buffer.resize(bufferCapacity);
	}

	#pragma endregion


	#pragma region InterfaceImplementation

	virtual void AddValue(const B& value)
	{
		std::lock_guard<std::mutex> lock(_locker);

		if (_buffer.size() == _bufferCapacity) _buffer.pop_front();
		_buffer.push_back(value);
	}

	virtual bool GetValue(B & value)
	{
		std::lock_guard<std::mutex> lock(_locker);
		if (_buffer.size() == 0) return false;

		value = _buffer.front();
		_buffer.pop_front();
		return true;
	}

	virtual bool GetCurrentCursorPosition(B & value)
	{
		std::lock_guard<std::mutex> lock(_locker);
		if (_buffer.size() == 0) return false;
		value = _buffer.back();
		return true;
	}

	#pragma endregion
};

#endif