//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "OSTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "AOS/Identify/Library.hpp"
#include "MUI/Listview.hpp"

namespace Components
{
    OSTab::OSTab()
      : mOSNumberText(ValueText("Operating System Number"))
      , mOSVersionText(ValueText("Operating System Version"))
      , mExecVersionText(ValueText("Exec Version"))
      , mWBVersionText(ValueText("Workbench Version"))
      , mPowerPCOSText(ValueText("PowerPC OS"))
      , mLoadedLibrariesList(MUI::ListBuilder().tagConstructHookString().tagDestructHookString().object())
      , mTCPStack(ValueText("TCP/IP Stack"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
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
                       .tagChild(MUI::ListviewBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Loaded Libraries, Datatypes, ...")
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagList(mLoadedLibrariesList)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("TCP/IP Stack")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mTCPStack)
                                     .object())
                       .object())
    {
        mOSVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::OSVER));
        mOSNumberText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::OSNR));
        mExecVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::EXECVER));
        mWBVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::WBVER));
        mPowerPCOSText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::PPCOS));
        mTCPStack.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::TCPIP));
        mLoadedLibrariesList.InsertSorted([]() -> std::vector<std::string> {
            std::vector<std::string> result;
            for (const auto &entry : AOS::Exec::Library::GetAllLibraryNodeNames())
                result.push_back(entry.name + " (v" + entry.version.value_or("??") + ")");
            return result;
        }());
    }
}
