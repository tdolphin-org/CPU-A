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
    class MainboardTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mSystemText;
        MUI::Text mChipsetText;
        MUI::Text mGaryText;
        MUI::Text mRamseyText;
        MUI::Text mAgnusText;
        MUI::Text mAgnusModeText;
        MUI::Text mDeniseText;
        MUI::Text mDeniseRevisionText;
        MUI::Text mPaulaText;
        MUI::Text mRTCText;
        MUI::Text mBatteryClockText;
        MUI::Text mROMVersionText;
        MUI::Text mROMSizeText;

        // BATTCLOCK Battery Backed Up Clock

        MUI::Group mComponent;

      public:
        MainboardTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}