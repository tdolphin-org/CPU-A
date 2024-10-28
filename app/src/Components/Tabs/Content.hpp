//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "TabsContainer.hpp"

#include "MUI/Image.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
        MUI::Text mCPUNameText;
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
        MUI::Group mCPUGroup;

        MUI::Group mMainboardGroup;
        MUI::Group mMemoryGroup;
        MUI::Group mGraphicsGroup;
        MUI::Group mExpansionsGroup;
        MUI::Group mBenchGroup;
        MUI::Group mAboutGroup;

        TabsContainer mComponent;

      public:
        Content();

        MUI::Text LabelText(const std::string &label);
        MUI::Text ValueText(const std::string &help, const std::string &defaultValue = "--");

      protected:
        MUI::Group &muiRoot() const
        {
            return mComponent;
        }
    };
}
