//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Content.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "MUI/Text.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    Content::Content()
      : mGraphicsGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Graphics")).object())
      , mBenchGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Bench")).object())
      , mComponent({
            { Label::CPUTab, mCPUTab },
            { Label::MainboardTab, mMainboardTab },
            { Label::MemoryTab, mMemoryTab },
            { Label::GraphicsTab, mGraphicsGroup },
            { Label::ExpansionsTab, mExpansionsTab },
            { Label::OperatingSystemTab, mOperatingSystemTab },
            { Label::BenchTab, mBenchGroup },
            { Label::AboutTab, mAboutTab },
        })
    {
    }
}
