//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "Content.hpp"

#include "TextResources/Labels.hpp"

namespace Components
{
    Content::Content()
      : mComponent({
            { Label::CPUTab, mCPUTab },
            { Label::MainboardTab, mMainboardTab },
            { Label::MemoryTab, mMemoryTab },
            { Label::GraphicsTab, mGraphicsTab },
            { Label::ExpansionsTab, mExpansionsTab },
            { Label::OperatingSystemTab, mOperatingSystemTab },
            { Label::BenchTab, mBenchTab },
            { Label::AboutTab, mAboutTab },
        })
    {
    }
}
