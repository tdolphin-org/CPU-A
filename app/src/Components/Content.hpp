//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Tabs/CPUTab.hpp"
#include "Tabs/MainboardTab.hpp"
#include "Tabs/OSTab.hpp"
#include "Tabs/TabsContainer.hpp"

#include "MUI/Text.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
        CPUTab mCPUTab;
        MainboardTab mMainboardTab;
        MUI::Group mMemoryGroup;
        MUI::Group mGraphicsGroup;
        MUI::Group mExpansionsGroup;
        OSTab mOperatingSystemTab;
        MUI::Group mBenchGroup;
        MUI::Group mAboutGroup;

        TabsContainer mComponent;

      public:
        Content();

      protected:
        MUI::Group &muiRoot() const
        {
            return mComponent;
        }
    };
}
