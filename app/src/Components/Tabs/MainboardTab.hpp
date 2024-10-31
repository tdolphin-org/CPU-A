//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "../Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class MainboardTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mSystemText;
        MUI::Text mChipsetText;
        MUI::Text mROMVersionText;
        MUI::Text mROMSizeText;

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