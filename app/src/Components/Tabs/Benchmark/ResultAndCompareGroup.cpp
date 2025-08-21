//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "ResultAndCompareGroup.hpp"

#include "DataInfo/BenchmarkData.hpp"
#include "MUI/Core/MakeObject.hpp"
#include <cmath>

namespace Components
{
    const static long defaultMaxBenchValue = 100;

    ResultAndCompareGroup::ResultAndCompareGroup()
      : mThisProcessorResultGauge(MUI::GaugeBuilder().tagHoriz(true).tagInfoText("%ld").tagMax(defaultMaxBenchValue).object())
      , mReferenceProcessorResultGauge(MUI::GaugeBuilder().tagHoriz(true).tagInfoText("%ld").tagMax(defaultMaxBenchValue).object())
      , mComponent(MUI::GroupBuilder()
                       .tagColumns(2)
                       .tagChild(MUI::MakeObject::FreeLabel1("This Processor"))
                       .tagChild(mThisProcessorResultGauge)
                       .tagChild(MUI::MakeObject::FreeLabel1("Reference"))
                       .tagChild(mReferenceProcessorResultGauge)
                       .object())
    {
        // Constructor implementation
    }

    void ResultAndCompareGroup::UpdateForSelection(long selection)
    {
        mReferenceProcessorResultGauge.setCurrent(DataInfo::reference2benchData.at((DataInfo::ReferenceID)selection).benchmark01result);
    }

    void ResultAndCompareGroup::UpdateThisProcessorResult(uint64_t operationsPerSecond)
    {
        mThisProcessorResultGauge.setCurrent(operationsPerSecond);
        auto max = RecalculateMax(operationsPerSecond, mReferenceProcessorResultGauge.getCurrent());

        mThisProcessorResultGauge.setMax(max);
        mReferenceProcessorResultGauge.setMax(max);
    }

    unsigned long ResultAndCompareGroup::RecalculateMax(const uint64_t operationsPerSecond, const uint64_t referenceOperationsPerSecond)
    {
        auto max = std::max(operationsPerSecond, referenceOperationsPerSecond);

        unsigned long newMax = static_cast<unsigned long>(std::pow(10, std::ceil(std::log10(max))));
        if (newMax < 100)
            newMax = defaultMaxBenchValue;

        return newMax;
    }
}
