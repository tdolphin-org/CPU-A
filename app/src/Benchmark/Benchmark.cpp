//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "Benchmark.hpp"

#include "AOS/Devices/Timer/TimerDevice.hpp"

#include <clib/timer_protos.h>
#include <proto/exec.h>

#ifdef TRACE
#include "amiga_std_light/iostream.hpp"
#endif

extern "C"
{
    void Benchmark01asm(long loops, long repeat);
}

namespace Benchmark::MC68k
{
    uint64_t OperationsPerFrequency(uint64_t ticks, uint64_t operations, uint64_t frequency)
    {
        if (ticks == 0 || operations == 0 || frequency == 0)
            return 0;

        return (operations * frequency) / ticks;
    }

    void Benchmark01(BenchResult &result)
    {
        static const long benchRepeatCount = 1000;
        struct EClockVal tvBegin = {}, tvEnd = {};

        uint64_t frequency = AOS::Devices::TimerDevice::instance().devReadEClock(tvBegin);

#ifdef TRACE
        std::cout << "EClock frequency: " << frequency << " ticks/sec" << std::endl;
        std::cout << "Starting benchmark..." << std::endl;
        std::cout << "Benchmarking with with " << result.operationsPerBench << " operations with internal " << benchRepeatCount
                  << " repeats." << std::endl;
#endif

        // benchmarking

        AOS::Devices::TimerDevice::instance().devReadEClock(tvBegin);
        Benchmark01asm(result.operationsPerBench, benchRepeatCount);
        AOS::Devices::TimerDevice::instance().devReadEClock(tvEnd);

        result.durationTicks = AOS::Devices::TimerDevice::instance().EClockDiff(tvBegin, tvEnd);
        result.durationInSeconds = result.durationTicks / frequency;
        result.operationsPerSecond = OperationsPerFrequency(result.durationTicks, result.operationsPerBench, frequency);
    }
}
