//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Tabs/TabsContainer.hpp"
#include "Tabs/MainboardTab.hpp"
#include "Tabs/CPUTab.hpp"

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
