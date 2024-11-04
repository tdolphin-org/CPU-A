//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "OSTab.hpp"

#include "AOS/Identify/Library.hpp"

namespace Components
{
    OSTab::OSTab()
      : mOSNumberText(ValueText("Operating System Number"))
      , mOSVersionText(ValueText("Operating System Version"))
      , mExecVersionText(ValueText("Exec Version"))
      , mWBVersionText(ValueText("Workbench Version"))
      , mPowerPCOSText(ValueText("PowerPC OS"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Operating System")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Number"))
                                     .tagChild(mOSNumberText)
                                     .tagChild(LabelText(MUIX_R "Version"))
                                     .tagChild(mOSVersionText)
                                     .tagChild(LabelText(MUIX_R "Exec"))
                                     .tagChild(mExecVersionText)
                                     .tagChild(LabelText(MUIX_R "Workbench"))
                                     .tagChild(mWBVersionText)
                                     .tagChild(LabelText(MUIX_R "PowerPC OS"))
                                     .tagChild(mPowerPCOSText)
                                     .object())
                       .object())
    {
        mOSVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::OSVER));
        mOSNumberText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::OSNR));
        mExecVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::EXECVER));
        mWBVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::WBVER));
        mWBVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::PPCOS));
    }
}
