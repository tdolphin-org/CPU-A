//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "CPUInfo.hpp"

#include "AOS/Expansion/ValueTypes/ManufacturerID.hpp"
#include "AppContext.hpp"
#include "FileResources/CPUImages.hpp"

#include <numeric>

using namespace AOS::Identify;

std::map<IDCPU, std::string> m68k_cpu2image = {
    { IDCPU::MC68000, CPUImageFile::mc68000 },   { IDCPU::MC68010, CPUImageFile::mc68010 },   { IDCPU::MC68020, CPUImageFile::mc68020 },
    { IDCPU::MC68030, CPUImageFile::mc68030 },   { IDCPU::MC68EC030, CPUImageFile::mc68030 }, { IDCPU::MC68040, CPUImageFile::mc68040 },
    { IDCPU::MC68LC040, CPUImageFile::mc68040 }, { IDCPU::MC68060, CPUImageFile::mc68060 },   { IDCPU::MC68LC060, CPUImageFile::mc68060 },
    { IDCPU::FPGA, CPUImageFile::fpga },         { IDCPU::EMU68, CPUImageFile::emu68 },       { IDCPU::OTHER, CPUImageFile::unknown },
};

std::map<IDPPC, std::string> ppc_cpu2image = {
    { IDPPC::NONE, CPUImageFile::none },     { IDPPC::OTHER, CPUImageFile::other },     { IDPPC::PPC602, CPUImageFile::ppc602 },
    { IDPPC::PPC603, CPUImageFile::ppc603 }, { IDPPC::PPC603E, CPUImageFile::ppc603e }, { IDPPC::PPC603P, CPUImageFile::ppc603p },
    { IDPPC::PPC604, CPUImageFile::ppc604 }, { IDPPC::PPC604E, CPUImageFile::ppc604e }, { IDPPC::PPC620, CPUImageFile::ppc620 },
};

namespace Components
{
    const char *CPUInfo::mCPUs[] = { "MC68k", "PowerPC", nullptr };

    CPUInfo::CPUInfo(const AOS::Identify::CpuInfo &cpuInfo)
      : mCPUSpec(cpuInfo.type == CpuType::MC68k
                     ? (cpuInfo.model.m68k == IDCPU::FPGA
                                && AppContext::instance().hasOneOfExpansions((unsigned short)AOS::Expansion::ManufacturerID::Apollo,
                                                                             { 1, 2, 3, 4, 5, 6, 7 })
                            ? DataInfo::fpga2spec.at(DataInfo::FPGAID::ACA68080)
                            : DataInfo::cpuMC68k2spec.at([&]() {
                                  auto pos = DataInfo::cpuMC68k2spec.find(cpuInfo.model.m68k);
                                  if (pos != DataInfo::cpuMC68k2spec.end())
                                      return cpuInfo.model.m68k;
                                  return IDCPU::OTHER;
                              }()))
                     : DataInfo::cpuPPC2spec.at([&]() {
                           auto pos = DataInfo::cpuPPC2spec.find(cpuInfo.model.ppc);
                           if (pos != DataInfo::cpuPPC2spec.end())
                               return cpuInfo.model.ppc;
                           return IDPPC::OTHER;
                       }()))
      , mCPUVendorText(ValueText("Vendor of CPU", mCPUSpec.vendor))
      , mCPUModelText(ValueText("Model of CPU", mCPUSpec.modelName))
      , mCPURevisionText(ValueText("Revision of CPU", cpuInfo.revision))
      , mCPUTDPText(ValueText("Maximal Thermal Design Power", mCPUSpec.tdp))
      , mCPUCoreVoltageText(ValueText("CPU/Core Voltage", mCPUSpec.coreVoltage))
      , mCPUTechnologyText(ValueText("Production Technology", mCPUSpec.technology))
      , mCPUPremiereYearText(ValueText("Year of Premiere", mCPUSpec.premiere))
      , mAdditionalUnits(ValueText("Additional Units like FPU, MMU"))
      , mCPUImage(MUI::ImageBuilder()
                      .tagSpecPicture((cpuInfo.type == CpuType::MC68k) ? m68k_cpu2image.at(cpuInfo.model.m68k)
                                                                       : ppc_cpu2image.at(cpuInfo.model.ppc))
                      .tagFixWidth(64)
                      .tagFixHeight(64)
                      .tagFreeHoriz(true)
                      .tagFreeVert(true)
                      .object())
      , mCPUClockText(ValueText("CPU clock", cpuInfo.clock))
      , mCPUMultipler(ValueText("Multiplier", "--"))
      , mCPUBusSpeed(ValueText("Bus Speed"))
      , mCPUL1Instructions(ValueText("Level 1 Instructions Cache size",
                                     mCPUSpec.l1InstructionCache > 0 ? ToString::FromBytesValue(mCPUSpec.l1InstructionCache) : "--"))
      , mCPUL1Data(ValueText("Level 1 Data Cache size", mCPUSpec.l1DataCache > 0 ? ToString::FromBytesValue(mCPUSpec.l1DataCache) : "--"))
      , mCPULevel2(ValueText("Level 2 Cache size", mCPUSpec.l2Cache > 0 ? ToString::FromBytesValue(mCPUSpec.l2Cache) : "--"))
      , mCPULevel3(ValueText("Level 3 Cache size", mCPUSpec.l3Cache > 0 ? ToString::FromBytesValue(mCPUSpec.l3Cache) : "--"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
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
                                                                                             .tagChild(LabelText("rev."))
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
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("Additional/Integrated Units")
                                     .tagChild(mAdditionalUnits)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagFrame(MUI::Frame::Group)
                                                   .tagBackground(MUI::ImageOrBackground::WindowBack)
                                                   .tagFrameTitle("Clocks (Core #0)")
                                                   .tagColumns(4)
                                                   .tagChild(LabelText(MUIX_R "Core Speed"))
                                                   .tagChild(mCPUClockText)
                                                   .tagChild(LabelText(MUIX_R "Multiplier"))
                                                   .tagChild(mCPUMultipler)
                                                   .tagChild(LabelText(MUIX_R "Bus Speed"))
                                                   .tagChild(mCPUBusSpeed)
                                                   .object())
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagFrame(MUI::Frame::Group)
                                                   .tagBackground(MUI::ImageOrBackground::WindowBack)
                                                   .tagFrameTitle("Cache")
                                                   .tagColumns(4)
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
        mAdditionalUnits.setContents(
            std::accumulate(cpuInfo.additionalUnits.begin(), cpuInfo.additionalUnits.end(), std::string(""),
                            [](const std::string &a, const std::string &b) { return a + (a.empty() ? "" : ", ") + b; }));
    }
}
