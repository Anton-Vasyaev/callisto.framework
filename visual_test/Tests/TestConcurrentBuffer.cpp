//
// Copyright (c) 2019
// Vasyaev Anton
//

// parent header
#include <Tests/TestConcurrentBuffer.hpp>
// test component
#include <Templates/ConcurrentBuffer.hpp>
// macros
#include <Macros/Types.hpp>
// std
#include <iostream>
#include <utility>
#include <vector>
#include <chrono>
#include <thread>

namespace chr = std::chrono;


bool processing;


template<typename T>
void produce(
    ConcurrentBuffer<T>& buffer, 
    std::vector<T>& productValues
)
{
    while(!processing);
    auto start = chr::high_resolution_clock::now();
    
    for(auto& value : productValues) buffer.AddValue(value);
    processing = false;
    auto end = chr::high_resolution_clock::now();

    std::cout   << "Procuce id processing "
                << chr::duration_cast<chr::microseconds>(end - start).count() << " us\n";
}

template<typename T>
void consume(
    int consume_id,
    ConcurrentBuffer<T>& buffer
)
{
    while(!processing);
    T value;
    auto start = chr::high_resolution_clock::now();
    while(processing || buffer.GetValue(value)) { }
    auto end = chr::high_resolution_clock::now();

    std::cout   << "Consume " << consume_id << ": processing:"
                << chr::duration_cast<chr::microseconds>(end - start).count() << " us\n";
}



void test_concurrent_buffer()
{
    t_size valuesSize = 1024ull * 1024ull;
    std::vector<t_uint64> values;
    values.reserve(valuesSize);
    for(t_size i = 0; i < valuesSize; i++) values.push_back(i);

    ConcurrentBuffer<t_uint64> buffer;
    std::thread produce_thread(produce<t_uint64>, std::ref(buffer), std::ref(values));
    std::thread consume_thread(consume<t_uint64>, 0,  std::ref(buffer));

    produce_thread.join();
    consume_thread.join();
}