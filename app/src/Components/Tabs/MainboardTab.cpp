//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "MainboardTab.hpp"

#include "AOS/Identify/Library.hpp"

namespace Components
{
    MainboardTab::MainboardTab()
      : mSystemText(ValueText("Hardware System"))
      , mComponent(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(
                    MUI::GroupBuilder().tagFrame(MUI::Frame::ReadList).tagFrameTitle("Hardware System").tagChild(mSystemText).object())
                .object())
    {
        mSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::SYSTEM));
    }
}