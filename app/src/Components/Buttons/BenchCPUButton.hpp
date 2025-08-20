//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"
#include "MUI/Gauge.hpp"

namespace Components
{
    class BenchCPUButton : public BasicButton
    {
        MUI::Gauge &mResultGauge;

      public:
        BenchCPUButton(MUI::Gauge &resultGauge, const std::string &label, const std::string &shortHelp, const long weight = -1);

      protected:
        unsigned long OnClick();
    };
}
