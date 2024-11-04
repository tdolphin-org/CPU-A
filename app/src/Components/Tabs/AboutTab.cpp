//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "AboutTab.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "ProgDefines.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    AboutTab::AboutTab()
      : mComponent(MUI::GroupBuilder()
                       .tagFrame(MUI::Frame::Group)
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(MUI::TextBuilder().tagContents(Label::AboutContent).object())
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
    }
}
