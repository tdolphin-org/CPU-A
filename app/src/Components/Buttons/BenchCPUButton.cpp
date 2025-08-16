//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "BenchCPUButton.hpp"

#include "AppContext.hpp"
#include "ProgDefines.hpp"

namespace Components
{
    BenchCPUButton::BenchCPUButton(const std::string &label, const std::string &shortHelp, const long weight)
      : BasicButton(label, shortHelp, weight)
    {
    }

    unsigned long BenchCPUButton::OnClick()
    {
        // TODO implement benchmark logic
        MuiAlert("Benchmarking MC68k CPU... Not implemented yet");
        return 0;
    }
}
