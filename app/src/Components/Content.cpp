//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Content.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "MUI/Text.hpp"
#include "ProgDefines.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    Content::Content()
      : mMemoryGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Memory")).object())
      , mGraphicsGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Graphics")).object())
      , mBenchGroup(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Bench")).object())
      , mAboutGroup(MUI::GroupBuilder()
                        .vertical()
                        .tagChild(MUI::MakeObject::HBar(0))
                        .tagChild(MUI::MakeObject::FreeLabel(APP_DESCRIPTION))
                        .tagChild(MUI::MakeObject::HBar(0))
                        .object())
      , mComponent({
            { Label::CPUTab, mCPUTab },
            { Label::MainboardTab, mMainboardTab },
            { Label::MemoryTab, mMemoryGroup },
            { Label::GraphicsTab, mGraphicsGroup },
            { Label::ExpansionsTab, mExpansionsTab },
            { Label::OperatingSystemTab, mOperatingSystemTab },
            { Label::BenchTab, mBenchGroup },
            { Label::AboutTab, mAboutGroup },
        })
    {
    }
}
