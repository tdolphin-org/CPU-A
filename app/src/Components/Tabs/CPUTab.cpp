//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "CPUTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "DataInfo/CPUSpec.hpp"
#include "FileResources/CPUImages.hpp"
#include "MUI/Core/MakeObject.hpp"

#include <numeric>

using namespace AOS::Identify;

std::map<IDCPU, std::string> cpu2image = {
    { IDCPU::MC68000, CPUImageFile::mc68000 },   { IDCPU::MC68010, CPUImageFile::mc68010 },   { IDCPU::MC68020, CPUImageFile::mc68020 },
    { IDCPU::MC68030, CPUImageFile::mc68030 },   { IDCPU::MC68EC030, CPUImageFile::mc68030 }, { IDCPU::MC68040, CPUImageFile::mc68040 },
    { IDCPU::MC68LC040, CPUImageFile::mc68040 }, { IDCPU::MC68060, CPUImageFile::mc68060 },   { IDCPU::MC68LC060, CPUImageFile::mc68060 },
    { IDCPU::FPGA, CPUImageFile::fpga },         { IDCPU::EMU68, CPUImageFile::emu68 },
};

namespace Components
{
    const char *CPUTab::mCPUs[] = { "MC68k", "PowerPC", nullptr };

    CPUTab::CPUTab()
      : mCPUVendorText(ValueText("Vendor of CPU"))
      , mCPUModelText(ValueText("Model of CPU"))
      , mCPURevisionText(ValueText("Revision of CPU"))
      , mCPUCoreVoltageText(ValueText("CPU/Core Voltage"))
      , mCPUTDPText(ValueText("Maximal Thermal Design Power"))
      , mCPUTechnologyText(ValueText("Production technology"))
      , mCPUPremiereYearText(ValueText("Year of premiere"))
      , mAdditionalUnits(ValueText("Additional Units like FPU, MMU"))
      , mCPUImage(MUI::ImageBuilder()
                      .tagSpecPicture(CPUImageFile::none)
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
      , mSelectionCycle(MUI::CycleBuilder().tagEntries(mCPUs).object())
      , mCPUCores(ValueText("Total number of Cores"))
      , mCPUThreads(ValueText("Total number of Threads"))
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
                                                                               .tagChild(MUI::GroupBuilder()
                                                                                             .horizontal()
                                                                                             .tagChild(mCPUModelText)
                                                                                             .tagChild(mCPURevisionText)
                                                                                             .object())
                                                                               .tagChild(LabelText(MUIX_R "Core Voltage"))
                                                                               .tagChild(mCPUCoreVoltageText)
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
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("Additional/Integrated Units")
                                     .tagChild(mAdditionalUnits)
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
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagChild(LabelText("Selection"))
                                     .tagChild(mSelectionCycle)
                                     .tagChild(LabelText("Cores"))
                                     .tagChild(mCPUCores)
                                     .tagChild(LabelText("Threads"))
                                     .tagChild(mCPUThreads)
                                     .object())
                       .object())
    {
        auto cpus = AOS::Identify::Library::GetAllCPUs();

        if (!cpus.empty())
        {
            auto &cpuSpec = DataInfo::cpuMC68k2spec.at(cpus.at(0).model.m68k);

            mCPUVendorText.setContents(cpuSpec.vendor);
            mCPUModelText.setContents(cpus.at(0).modelName);
            mCPURevisionText.setContents(cpus.at(0).revision);
            mCPUClockText.setContents(cpus.at(0).clock);
            mCPUCoreVoltageText.setContents(cpuSpec.coreVoltage);
            mCPUTechnologyText.setContents(cpuSpec.technology);
            mCPUTDPText.setContents(cpuSpec.tdp);
            mCPUPremiereYearText.setContents(cpuSpec.premiere);
            mCPUImage.setSpecPicture(cpu2image.at(cpus.at(0).model.m68k));
            mAdditionalUnits.setContents(
                std::accumulate(cpus.at(0).additionalUnits.begin(), cpus.at(0).additionalUnits.end(), std::string(""),
                                [](const std::string &a, const std::string &b) { return a + (a.empty() ? "" : ", ") + b; }));
            mCPUCores.setContents(std::to_string(cpuSpec.totalCores));
            mCPUThreads.setContents(std::to_string(cpuSpec.totalThreads));
        }
    }
}
