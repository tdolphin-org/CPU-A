//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "MUI/Text.hpp"

namespace Components
{
    class TabBase
    {
      public:
        MUI::Text LabelText(const std::string &label);
        MUI::Text ValueText(const std::string &help, const std::string &defaultValue = "--");
    };
}
