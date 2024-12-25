//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"

#include "MUI/Group.hpp"

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
