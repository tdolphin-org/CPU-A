//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Benchmark/ResultAndCompareGroup.hpp"
#include "Components/Buttons/BenchCPUButton.hpp"
#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "Components/MCC/ActionCycle.hpp"
#include "MUI/Group.hpp"

namespace Components
{
    class BenchTab : public Root<MUI::Group>, public TabBase, public MCC::ActionCycleDispatcher
    {
        ResultAndCompareGroup mResultAndCompareGroup;

        MUI::Cycle mSelectionCycle;
        MUI::Group mSingleCPUThreadGroup;
        BenchCPUButton mBenchCPUButton;

        MUI::Group mComponent;

      public:
        BenchTab();

      protected:
        // implements pure virtual MCC::ActionCycleDispatcher
        unsigned long OnCycle();

        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
