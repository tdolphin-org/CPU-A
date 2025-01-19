//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "CPUTab.hpp"

#include "DataInfo/CPUSpec.hpp"
#include "FileResources/CPUImages.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Image.hpp"

#include <numeric>

using namespace AOS::Identify;

namespace Components
{
    const char *CPUTab::mCPUs[] = { "MC68k", "PowerPC", nullptr };

    CPUTab::CPUTab()
      : mCPUInfos(AOS::Identify::Library::GetAllCPUs())
      , mM68kCPUInfo(mCPUInfos.at(0))
      , mPowerPCCPUInfo(mCPUInfos.at(1))
      , mCPUInfoGroup(MUI::GroupBuilder().tagPageMode().tagChild(mM68kCPUInfo).tagChild(mPowerPCCPUInfo).object())
      , mSelectionCycle(MCC::ActionCycleBuilder().tagEntries(mCPUs).object(*this))
      , mCPUCores(ValueText("Total number of Cores"))
      , mCPUThreads(ValueText("Total number of Threads"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(mCPUInfoGroup)
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagChild(LabelText(MUIX_R "Selection"))
                                     .tagChild(mSelectionCycle)
                                     .tagChild(LabelText(MUIX_R "Cores"))
                                     .tagChild(mCPUCores)
                                     .tagChild(LabelText(MUIX_R "Threads"))
                                     .tagChild(mCPUThreads)
                                     .object())
                       .object())
    {
        ShowInfo(0);
    }

    void CPUTab::ShowInfo(const int cpuIndex)
    {
        auto &cpuInfo = mCPUInfos.at(cpuIndex);

        auto &cpuSpec = (cpuInfo.type == CpuType::MC68k) ? DataInfo::cpuMC68k2spec.at(cpuInfo.model.m68k)
                                                         : DataInfo::cpuPPC2spec.at(cpuInfo.model.ppc);

        mCPUCores.setContents(cpuSpec.totalCores > 0 ? std::to_string(cpuSpec.totalCores) : "--");
        mCPUThreads.setContents(cpuSpec.totalThreads > 0 ? std::to_string(cpuSpec.totalThreads) : "--");
    }

    unsigned long CPUTab::OnCycle()
    {
        auto selection = mSelectionCycle.getActive();
        ShowInfo(selection);
        mCPUInfoGroup.setActivePage(selection);
        return 0;
    }
}
