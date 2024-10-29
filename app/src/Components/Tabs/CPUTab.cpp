//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "CPUTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "FileResources/CPUImages.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    CPUTab::CPUTab()
      : mCPUVendorText(ValueText("Vendor of CPU"))
      , mCPUModelText(ValueText("Model of CPU"))
      , mCPUVoltageText(ValueText("CPU/Core Voltage"))
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
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("Processor")
                                     .tagChild(MUI::GroupBuilder()
                                                   .horizontal()
                                                   .tagChild(MUI::GroupBuilder()
                                                                 .tagChild(MUI::GroupBuilder()
                                                                               .tagColumns(4)
                                                                               .tagChild(LabelText(MUIX_R "Vendor"))
                                                                               .tagChild(mCPUVendorText)
                                                                               .tagChild(LabelText(MUIX_R "Model"))
                                                                               .tagChild(mCPUModelText)
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
    {
        auto cpus = AOS::Identify::Library::GetAllCPUs();

        if (!cpus.empty())
        {
            // TODO get/detect real values
            mCPUVendorText.setContents("Motorola");
            mCPUModelText.setContents(cpus.at(0).model);
            mCPUClockText.setContents(cpus.at(0).clock);
            mCPUVoltageText.setContents("5 V");
            mCPUTechnologyText.setContents("2.0-3.5 \xB5m");
            mCPUTDPText.setContents("~0.7-1.5 W");
            mCPUPremiereYearText.setContents("1979");
        }
    }

    MUI::Text CPUTab::LabelText(const std::string &label)
    {
        return MUI::TextBuilder().tagContents(label).tagFrame(MUI::Frame::String).tagPhantomHoriz(true).tagWeight(0).object();
    }

    MUI::Text CPUTab::ValueText(const std::string &help, const std::string &defaultValue)
    {
        return MUI::TextBuilder()
            .tagFrame(MUI::Frame::String)
            .tagContents(defaultValue)
            .tagBackground(MUI::ImageOrBackground::StringActiveBack)
            .tagShortHelp(help)
            .object();
    }
}