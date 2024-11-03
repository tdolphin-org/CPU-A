//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Tabs/CPUTab.hpp"
#include "Tabs/ExpansionsTab.hpp"
#include "Tabs/MainboardTab.hpp"
#include "Tabs/MemoryTab.hpp"
#include "Tabs/OSTab.hpp"
#include "Tabs/TabsContainer.hpp"

#include "MUI/Text.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
        CPUTab mCPUTab;
        MainboardTab mMainboardTab;
        MemoryTab mMemoryTab;
        MUI::Group mGraphicsGroup;
        ExpansionsTab mExpansionsTab;
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
