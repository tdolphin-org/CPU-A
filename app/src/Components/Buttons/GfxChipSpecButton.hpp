//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"
#include "DataInfo/GfxChipSpec.hpp"

namespace Components
{
    class GfxChipSpecButton : public BasicButton
    {
        std::vector<DataInfo::GfxChipID> mChips;

      public:
        GfxChipSpecButton(const std::vector<DataInfo::GfxChipID> &chips);

      protected:
        unsigned long OnClick();
    };
}
