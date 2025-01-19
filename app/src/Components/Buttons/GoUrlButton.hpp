//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"

namespace Components
{
    class GoUrlButton : public BasicButton
    {
        std::string mUrl;

      public:
        GoUrlButton(const std::string &label, const std::string &shortHelp, const std::string &url, const long weight = -1);

      protected:
        unsigned long OnClick();
    };
}
