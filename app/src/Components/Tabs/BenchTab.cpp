//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "BenchTab.hpp"

#include "DataInfo/BenchmarkData.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "ProgDefines.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    const static long defaultMaxBenchValue = 100;

    BenchTab::BenchTab()
      : mThisProcessorResultGauge(MUI::GaugeBuilder().tagHoriz(true).tagInfoText("%ld").tagMax(defaultMaxBenchValue).object())
      , mReferenceProcessorResultGauge(MUI::GaugeBuilder().tagHoriz(true).tagInfoText("%ld").tagMax(defaultMaxBenchValue).object())
      , mSelectionCycle(MCC::ActionCycleBuilder().tagEntries(DataInfo::benchmarkReferences).object(*this))
      , mSingleCPUThreadGroup(
            MUI::GroupBuilder()
                .tagFrame(MUI::Frame::Group)
                .tagFrameTitle("Single M68k CPU Thread")
                .tagBackground(MUI::ImageOrBackground::WindowBack)
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(2)
                              .tagChild(MUI::MakeObject::FreeLabel1("This Processor"))
                              .tagChild(mThisProcessorResultGauge)
                              .tagChild(MUI::MakeObject::FreeLabel1("Reference"))
                              .tagChild(mReferenceProcessorResultGauge)
                              .object())
                .tagChild(
                    MUI::GroupBuilder().horizontal().tagChild(MUI::MakeObject::FreeLabel1("Reference")).tagChild(mSelectionCycle).object())
                .object())
      , mBenchCPUButton(mThisProcessorResultGauge, MUIX_C "Bench MC68k CPU", "Run MC68k benchmark", -1)
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(mSingleCPUThreadGroup)
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .tagChild(mBenchCPUButton)
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .object())
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
        BenchTab::OnCycle();
    }

    unsigned long BenchTab::OnCycle()
    {
        auto selection = mSelectionCycle.getActive();
        mReferenceProcessorResultGauge.setCurrent(DataInfo::reference2benchData.at((DataInfo::ReferenceID)selection).benchmark01result);
        return 0;
    }
}
