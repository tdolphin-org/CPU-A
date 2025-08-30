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
#include "TextResources/Labels.hpp"

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
        if (callback == nullptr)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " nullptr callback!";
            throw std::runtime_error(error);
        }
    }

    unsigned long BenchCPUButton::OnClick()
    {
        static const int multiplier = 5;
        static const int maxRetries = 5;
        static const int minDuration = 5;

        if (MuiRequest("Benchmark Warning",
                       "Warning: This benchmark will suspend multitasking, and your system may be unresponsive for up to one "
                       "minute. Do you want to proceed?",
                       Label::_ProceedOr_Cancel)
            == 0)
            return 0;

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
                std::cout << "#### Benchmark interval too short. Try a higher operation count." << std::endl;
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
