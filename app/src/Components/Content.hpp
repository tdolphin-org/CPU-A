//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Tabs/TabsContainer.hpp"
#include "Tabs/AboutTab.hpp"
#include "Tabs/CPUTab.hpp"
#include "Tabs/ExpansionsTab.hpp"
#include "Tabs/GraphicsTab.hpp"
#include "Tabs/MainboardTab.hpp"
#include "Tabs/MemoryTab.hpp"
#include "Tabs/OSTab.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
        CPUTab mCPUTab;
        MainboardTab mMainboardTab;
        MemoryTab mMemoryTab;
        GraphicsTab mGraphicsTab;
        ExpansionsTab mExpansionsTab;
        OSTab mOperatingSystemTab;
        MUI::Group mBenchGroup;
        AboutTab mAboutTab;

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
