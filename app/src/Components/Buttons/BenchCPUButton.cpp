//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "BenchCPUButton.hpp"

#include "AppContext.hpp"
#include "ProgDefines.hpp"
#include "Benchmark/Benchmark.hpp"

namespace Components
{
    BenchCPUButton::BenchCPUButton(const std::string &label, const std::string &shortHelp, const long weight)
      : BasicButton(label, shortHelp, weight)
    {
    }

    unsigned long BenchCPUButton::OnClick()
    {
        // TODO implement benchmark logic
        Benchmark::MC68k::Benchmark01();
        return 0;
    }
}
