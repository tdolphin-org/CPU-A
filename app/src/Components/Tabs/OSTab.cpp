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
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagColumns(4)
                                     .tagFrameTitle("Operating System")
                                     .tagChild(LabelText("Number"))
                                     .tagChild(mOSNumberText)
                                     .tagChild(LabelText("Version"))
                                     .tagChild(mOSVersionText)
                                     .tagChild(LabelText("Exec"))
                                     .tagChild(mExecVersionText)
                                     .tagChild(LabelText("Workbench"))
                                     .tagChild(mWBVersionText)
                                     .object())
                       .object())
    {
        mOSVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::OSVER));
        mOSNumberText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::OSNR));
        mExecVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::EXECVER));
        mWBVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::WBVER));
    }
}
