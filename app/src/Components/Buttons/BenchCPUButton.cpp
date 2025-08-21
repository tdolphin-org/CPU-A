//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "BenchCPUButton.hpp"

#include "AppContext.hpp"
#include "Benchmark/Benchmark.hpp"
#include "MUI/Application.hpp"
#include "ProgDefines.hpp"

#include <cmath>

#ifdef TRACE
#include "amiga_std_light/iostream.hpp"
#endif

namespace Components
{
    BenchCPUButton::BenchCPUButton(std::function<void(uint64_t)> callback, const std::string &label, const std::string &shortHelp,
                                   const long weight)
      : BasicButton(label, shortHelp, weight)
      , mCallback(callback)
    {
    }

    unsigned long BenchCPUButton::OnClick()
    {
        static const int multiplier = 5;
        static const int maxRetries = 5;
        static const int minDuration = 5;

        MUI::ApplicationSleepScope scope;
        // TODO implement benchmark logic
        Benchmark::MC68k::BenchResult result;
        for (int i = 0; i < maxRetries; ++i)
        {
            Benchmark::MC68k::Benchmark01(result);
#ifdef TRACE
            std::cout << "Benchmark completed:" << std::endl;
            std::cout << "Operations in bench: " << result.operationsPerBench << std::endl;
            std::cout << "Duration (ticks): " << result.durationTicks << std::endl;
            std::cout << "Duration (seconds): " << result.durationInSeconds << std::endl;
            std::cout << "Final operations per second: " << result.operationsPerSecond << std::endl;
#endif

            if (result.durationInSeconds < minDuration)
            {
#ifdef TRACE
                std::cout << "#### Benchmark too short. Try a higher operation count." << std::endl;
#endif
                result.operationsPerBench *= multiplier; // increase operations
            }
            else
                break;
        }

        // Call the callback function with the result
        if (mCallback)
            mCallback(result.operationsPerSecond);

        return 0;
    }
}
