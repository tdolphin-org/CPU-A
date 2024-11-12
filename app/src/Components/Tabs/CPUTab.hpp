//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/Identify/Library.hpp"
#include "Components/Core/Root.hpp"
#include "Components/MCC/ActionCycle.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUTab : public Root<MUI::Group>, public TabBase, public MCC::ActionCycleDispatcher
    {
        static const char *mCPUs[];

        std::vector<AOS::Identify::CpuInfo> mCPUInfos;

        MUI::Text mCPUVendorText;
        MUI::Text mCPUModelText;
        MUI::Text mCPURevisionText;
        MUI::Text mCPUTDPText;
        MUI::Text mCPUCoreVoltageText;
        MUI::Text mCPUTechnologyText;
        MUI::Text mCPUPremiereYearText;
        MUI::Text mAdditionalUnits; // like MMU, FPU
        MUI::Group mCPUImagesGroup;
        MUI::Text mCPUClockText;
        MUI::Text mCPUMultipler;
        MUI::Text mCPUBusSpeed;
        MUI::Text mCPUL1Instructions;
        MUI::Text mCPUL1Data;
        MUI::Text mCPULevel2;
        MUI::Text mCPULevel3;
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
