//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include <cstdint>

// Benchmarking functions for MC68k CPU
namespace Benchmark::MC68k
{
    struct BenchResult
    {
        uint64_t operationsPerBench = 20; // operations per bench
        uint64_t operationsPerSecond = 0;
        uint64_t durationTicks = 0; // duration in ticks
        unsigned long durationInSeconds = 0; // duration of the benchmark in seconds
    };

    /// @brief run benchmark v0.1
    /// @return result of the benchmark repetition count in one second
    void Benchmark01(BenchResult& result);
}
