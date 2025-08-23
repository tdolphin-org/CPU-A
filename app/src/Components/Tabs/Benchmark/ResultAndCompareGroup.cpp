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
      : mThisProcessorResultGauge(
            MUI::GaugeBuilder().tagHoriz(true).tagInfoText("Not benchmarked yet").tagMax(defaultMaxBenchValue).object())
      , mReferenceProcessorResultGauge(
            MUI::GaugeBuilder().tagHoriz(true).tagInfoText("%ld").tagCurrent(0).tagMax(defaultMaxBenchValue).object())
      , mComponent(MUI::GroupBuilder()
                       .tagColumns(2)
                       .tagChild(MUI::MakeObject::FreeLabel1("This Processor"))
                       .tagChild(mThisProcessorResultGauge)
                       .tagChild(MUI::MakeObject::FreeLabel1("Reference"))
                       .tagChild(mReferenceProcessorResultGauge)
                       .object())
    {
    }

    void ResultAndCompareGroup::UpdateForSelection(long selection)
    {
        Update(mThisProcessorResultGauge.getCurrent(),
               DataInfo::reference2benchData.at((DataInfo::ReferenceID)selection).benchmark01result);
    }

    void ResultAndCompareGroup::UpdateThisProcessorResult(uint64_t operationsPerSecond)
    {
        if (operationsPerSecond > 0)
            mThisProcessorResultGauge.setInfoText("%ld");

        Update(operationsPerSecond, mReferenceProcessorResultGauge.getCurrent());
    }

    void ResultAndCompareGroup::Update(const uint64_t operationsPerSecond, const uint64_t referenceOperationsPerSecond)
    {
        auto max = RecalculateMax(operationsPerSecond, referenceOperationsPerSecond);

        if (operationsPerSecond > 0)
        {
            mThisProcessorResultGauge.setMax(max);
            mThisProcessorResultGauge.setCurrent(operationsPerSecond);
        }

        mReferenceProcessorResultGauge.setMax(max);
        mReferenceProcessorResultGauge.setCurrent(referenceOperationsPerSecond);
    }

    unsigned long ResultAndCompareGroup::RecalculateMax(const uint64_t operationsPerSecond, const uint64_t referenceOperationsPerSecond)
    {
        auto max = std::max(operationsPerSecond, referenceOperationsPerSecond);

        if (max < 100)
            return defaultMaxBenchValue;

        if (max < 1000)
            return (max + 100) % 1000; // round to hundred

        if (max < 10000)
            return (max + 1000) % 10000; // round to thousand

        if (max < 100000)
            return (max + 10000) % 100000; // round to ten thousand

        return static_cast<unsigned long>(std::pow(10, std::ceil(std::log10(max))));
    }
}
