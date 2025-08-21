//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"

#include <functional>

namespace Components
{
    class BenchCPUButton : public BasicButton
    {
        std::function<void(uint64_t)> mCallback;

      public:
        BenchCPUButton(std::function<void(uint64_t)> callback, const std::string &label, const std::string &shortHelp,
                       const long weight = -1);

      protected:
        unsigned long OnClick();
    };
}
