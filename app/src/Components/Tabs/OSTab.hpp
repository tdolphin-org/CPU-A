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
#include "MUI/List.hpp"

namespace Components
{
    class OSTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mOSNumberText;
        MUI::Text mOSVersionText;
        MUI::Text mExecVersionText;
        MUI::Text mWBVersionText;
        MUI::Text mPowerPCOSText;

        MUI::Text mTCPStack;

        MUI::List mLoadedLibrariesList;

        MUI::Group mComponent;

      public:
        OSTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}