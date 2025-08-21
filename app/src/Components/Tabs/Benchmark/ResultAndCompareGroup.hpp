//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Gauge.hpp"
#include "MUI/Group.hpp"

namespace Components
{
    class ResultAndCompareGroup : public Root<MUI::Group>
    {
        MUI::Gauge mThisProcessorResultGauge;
        MUI::Gauge mReferenceProcessorResultGauge;

        MUI::Group mComponent;

      public:
        ResultAndCompareGroup();

        void UpdateForSelection(long selection);
        void UpdateThisProcessorResult(uint64_t operationsPerSecond);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }

      private:
        unsigned long RecalculateMax(const uint64_t operationsPerSecond, const uint64_t referenceOperationsPerSecond);
    };
}
