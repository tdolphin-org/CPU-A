//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "AOS/Identify/Library.hpp"
#include "Components/Core/Root.hpp"
#include "Components/Tabs/TabBase.hpp"
#include "DataInfo/CPUSpec.hpp"

#include "MUI/Group.hpp"
#include "MUI/Image.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUInfo : public Root<MUI::Group>, public TabBase
    {
        static const char *mCPUs[];

        DataInfo::CPUSpec mCPUSpec;

        MUI::Text mCPUVendorText;
        MUI::Text mCPUModelText;
        MUI::Text mCPURevisionText;
        MUI::Text mCPUTDPText;
        MUI::Text mCPUCoreVoltageText;
        MUI::Text mCPUTechnologyText;
        MUI::Text mCPUPremiereYearText;
        MUI::Text mAdditionalUnits; // like MMU, FPU
        MUI::Image mCPUImage;
        MUI::Text mCPUClockText;
        MUI::Text mCPUMultipler;
        MUI::Text mCPUBusSpeed;
        MUI::Text mCPUL1Instructions;
        MUI::Text mCPUL1Data;
        MUI::Text mCPULevel2;
        MUI::Text mCPULevel3;

        MUI::Group mComponent;

      public:
        CPUInfo(const AOS::Identify::CpuInfo &cpuInfo);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
