//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class MemoryTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mMainboardRAMAccessTimeText;
        MUI::Text mMainboardRAMWidthText;
        MUI::Text mMainboardRAMCASModeText;
        MUI::Text mMainboardRAMBandwidthText;
        MUI::Text mPlainChipRAMSizeText;
        MUI::Text mPlainFastRAMSizeText;
        MUI::Text mPlainSlowRAMSizeText;
        MUI::Text mVMMChipRamSizeText;
        MUI::Text mVMMFastRamSizeText;

        MUI::Group mComponent;

      public:
        MemoryTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}