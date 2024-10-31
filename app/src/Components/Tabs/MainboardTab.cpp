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
      , mChipsetText(ValueText("Installed Chipset"))
      , mROMVersionText(ValueText("ROM Version"))
      , mROMSizeText(ValueText("ROM Size"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagColumns(4)
                                     .tagFrameTitle("Hardware System")
                                     .tagChild(LabelText("Name"))
                                     .tagChild(mSystemText)
                                     .tagChild(LabelText("Chipset"))
                                     .tagChild(mChipsetText)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("ROM")
                                     .tagColumns(4)
                                     .tagChild(LabelText("Version"))
                                     .tagChild(mROMVersionText)
                                     .tagChild(LabelText("Size"))
                                     .tagChild(mROMSizeText)
                                     .object())
                       .object())
    {
        mSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::SYSTEM));
        mChipsetText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::CHIPSET));
        mROMVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::ROMVER));
        mROMSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::ROMSIZE));
    }
}
