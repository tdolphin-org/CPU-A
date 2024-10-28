//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Content.hpp"

#include "FileResources/CPUImages.hpp"
#include "MUI/Balance.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Text.hpp"
#include "ProgDefines.hpp"

namespace Components
{
    Content::Content()
      : mCPUNameText(ValueText("Full name (and revision) of CPU"))
      , mCPUVoltageText(ValueText("Core Voltage"))
      , mCPUTDPText(ValueText("Maximal Thermal Design Power"))
      , mCPUTechnologyText(ValueText("Production technology"))
      , mCPUPremiereYearText(ValueText("Year of premiere"))
      , mCPUImage(MUI::ImageBuilder()
                      .tagSpecPicture(CPUImageFile::mc68000)
                      .tagFixWidth(64)
                      .tagFixHeight(64)
                      .tagFreeHoriz(true)
                      .tagFreeVert(true)
                      .object())
      , mCPUClockText(ValueText("CPU clock"))
      , mCPUMultipler(ValueText("Multiplier", "x1"))
      , mCPUBusSpeed(ValueText("Bus Speed"))
      , mCPUL1Instructions(ValueText("Level 1 Instructions Cache size"))
      , mCPUL1Data(ValueText("Level 1 Data Cache size"))
      , mCPULevel2(ValueText("Level 2 Cache size"))
      , mCPULevel3(ValueText("Level 3 Cache size"))
      , mCPUGroup(MUI::GroupBuilder()
                      .vertical()
                      .tagChild(MUI::GroupBuilder()
                                    .tagFrame(MUI::Frame::ReadList)
                                    .tagFrameTitle("Processor")
                                    .tagChild(MUI::GroupBuilder()
                                                  .horizontal()
                                                  .tagChild(MUI::GroupBuilder()
                                                                .tagChild(MUI::GroupBuilder()
                                                                              .horizontal()
                                                                              .tagChild(LabelText(MUIX_R "Name"))
                                                                              .tagChild(mCPUNameText)
                                                                              .object())
                                                                .tagChild(MUI::GroupBuilder()
                                                                              .tagColumns(4)
                                                                              .tagChild(LabelText(MUIX_R "Voltage"))
                                                                              .tagChild(mCPUVoltageText)
                                                                              .tagChild(LabelText(MUIX_R "Technology"))
                                                                              .tagChild(mCPUTechnologyText)
                                                                              .tagChild(LabelText(MUIX_R "Max TDP"))
                                                                              .tagChild(mCPUTDPText)
                                                                              .tagChild(LabelText(MUIX_R "Premiere"))
                                                                              .tagChild(mCPUPremiereYearText)
                                                                              .object())

                                                                .object())
                                                  .tagChild(mCPUImage)
                                                  .object())
                                    .object())
                      .tagChild(MUI::GroupBuilder()
                                    .horizontal()
                                    .tagChild(MUI::GroupBuilder()
                                                  .tagFrame(MUI::Frame::ReadList)
                                                  .tagFrameTitle("Clocks (Core #0)")
                                                  .tagColumns(2)
                                                  .tagChild(LabelText(MUIX_R "Core Speed"))
                                                  .tagChild(mCPUClockText)
                                                  .tagChild(LabelText(MUIX_R "Multiplier"))
                                                  .tagChild(mCPUMultipler)
                                                  .tagChild(LabelText(MUIX_R "Bus Speed"))
                                                  .tagChild(mCPUBusSpeed)
                                                  .object())
                                    .tagChild(MUI::GroupBuilder()
                                                  .tagFrame(MUI::Frame::ReadList)
                                                  .tagFrameTitle("Cache")
                                                  .tagColumns(2)
                                                  .tagChild(LabelText(MUIX_R "L1 Inst."))
                                                  .tagChild(mCPUL1Instructions)
                                                  .tagChild(LabelText(MUIX_R "L1 Data"))
                                                  .tagChild(mCPUL1Data)
                                                  .tagChild(LabelText(MUIX_R "Level 2"))
                                                  .tagChild(mCPULevel2)
                                                  .tagChild(LabelText(MUIX_R "Level 3"))
                                                  .tagChild(mCPULevel3)
                                                  .object())
                                    .object())
                      .object())
      , mMainboardGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Mainboard")).object())
      , mMemoryGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Memory")).object())
      , mGraphicsGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Graphics")).object())
      , mExpansionsGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Expansions")).object())
      , mBenchGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Bench")).object())
      , mAboutGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel(APP_DESCRIPTION)).object())
      , mComponent({
            { "CPU", mCPUGroup },
            { "Mainboard", mMainboardGroup },
            { "Memory", mMemoryGroup },
            { "Graphics", mGraphicsGroup },
            { "Expansions", mExpansionsGroup },
            { "Bench", mBenchGroup },
            { "About", mAboutGroup },
        })
    {
        // TODO get/detect real values
        // mock values
        mCPUNameText.setContents("Motorola 68000");
        mCPUClockText.setContents("8 MHz");
        mCPUVoltageText.setContents("5 V");
        mCPUTechnologyText.setContents("2.0-3.5 \xB5m");
        mCPUTDPText.setContents("~0.7-1.5 W");
        mCPUPremiereYearText.setContents("1979");
    }

    MUI::Text Content::LabelText(const std::string &label)
    {
        return MUI::TextBuilder().tagContents(label).tagFrame(MUI::Frame::String).tagPhantomHoriz(true).tagWeight(0).object();
    }

    MUI::Text Content::ValueText(const std::string &help, const std::string &defaultValue)
    {
        return MUI::TextBuilder()
            .tagFrame(MUI::Frame::String)
            .tagContents(defaultValue)
            .tagBackground(MUI::ImageOrBackground::StringActiveBack)
            .tagShortHelp(help)
            .object();
    }
}
