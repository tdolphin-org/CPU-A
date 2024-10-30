//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "../Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Cycle.hpp"
#include "MUI/Group.hpp"
#include "MUI/Image.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUTab : public Root<MUI::Group>, public TabBase
    {
        static const char *mCPUs[];

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
        MUI::Cycle mSelectionCycle;
        MUI::Text mCPUCores;
        MUI::Text mCPUThreads;

        MUI::Group mComponent;

      public:
        CPUTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
