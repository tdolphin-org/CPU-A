//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"

namespace Components
{
    class BenchCPUButton : public BasicButton
    {
      public:
        BenchCPUButton(const std::string &label, const std::string &shortHelp, const long weight = -1);

      protected:
        unsigned long OnClick();
    };
}
