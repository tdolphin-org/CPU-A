//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "../Core/Root.hpp"

#include "MUI/Group.hpp"
#include "MUI/Image.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUTab : public Root<MUI::Group>
    {
        MUI::Text mCPUVendorText;
        MUI::Text mCPUModelText;
        MUI::Text mCPUTDPText;
        MUI::Text mCPUVoltageText;
        MUI::Text mCPUTechnologyText;
        MUI::Text mCPUPremiereYearText;
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
        CPUTab();

        MUI::Text LabelText(const std::string &label);
        MUI::Text ValueText(const std::string &help, const std::string &defaultValue = "--");

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}