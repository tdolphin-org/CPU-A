//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "CPU/CPUInfo.hpp"
#include "Components/Tabs/TabBase.hpp"

#include "AOS/Identify/Library.hpp"
#include "Components/Core/Root.hpp"
#include "Components/MCC/ActionCycle.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUTab : public Root<MUI::Group>, public TabBase, public MCC::ActionCycleDispatcher
    {
        static const char *mCPUs[];

        std::vector<AOS::Identify::CPUInfo> mCPUInfos;

        CPUInfo mM68kCPUInfo;
        CPUInfo mPowerPCCPUInfo;
        MUI::Group mCPUInfoGroup;
        MUI::Cycle mSelectionCycle;
        MUI::Text mCPUCores;
        MUI::Text mCPUThreads;

        MUI::Group mComponent;

      public:
        CPUTab();

        void ShowInfo(const int cpuIndex);

      protected:
        // implements pure virtual MCC::ActionCycleDispatcher
        unsigned long OnCycle();

      private:
        void Clear();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
