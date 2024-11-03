//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "MainboardTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    MainboardTab::MainboardTab()
      : mSystemText(ValueText("Hardware System Name"))
      , mChipsetText(ValueText("Installed Chipset"))
      , mGaryText(ValueText("Gary"))
      , mRamseyText(ValueText("Ramsey"))
      , mAgnusText(ValueText("Agnus/Alice/.. Type and Revision"))
      , mAgnusModeText(ValueText("Agnus/Alice/.. Mode"))
      , mDeniseText(ValueText("Denise/Lisa/.. Model"))
      , mDeniseRevisionText(ValueText("Denise/Lisa/.. Revision"))
      , mPaulaText(ValueText("Paula"))
      , mRTCText(ValueText("Realtime Clock"))
      , mBatteryClockText(ValueText("Battery Backed Up Clock"))
      , mROMVersionText(ValueText("ROM Version"))
      , mROMSizeText(ValueText("ROM Size"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("Hardware System")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mSystemText)
                                     .tagChild(LabelText(MUIX_R "Chipset"))
                                     .tagChild(mChipsetText)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("Custom Chips")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Gary"))
                                     .tagChild(mGaryText)
                                     .tagChild(LabelText(MUIX_R "Ramsey"))
                                     .tagChild(mRamseyText)
                                     .tagChild(LabelText(MUIX_R "Graphics Controller"))
                                     .tagChild(mAgnusText)
                                     .tagChild(LabelText(MUIX_R "Mode"))
                                     .tagChild(mAgnusModeText)
                                     .tagChild(LabelText(MUIX_R "Display Controller"))
                                     .tagChild(mDeniseText)
                                     .tagChild(LabelText(MUIX_R "Revision"))
                                     .tagChild(mDeniseRevisionText)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("Realtime Clock")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mRTCText)
                                     .tagChild(LabelText(MUIX_R "Backed Up"))
                                     .tagChild(mBatteryClockText)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::ReadList)
                                     .tagFrameTitle("ROM")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Version"))
                                     .tagChild(mROMVersionText)
                                     .tagChild(LabelText(MUIX_R "Size"))
                                     .tagChild(mROMSizeText)
                                     .object())
                       .object())
    {
        mSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::SYSTEM));
        mChipsetText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::CHIPSET));

        mGaryText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::GARY));
        mRamseyText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::RAMSEY));
        mAgnusText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::AGNUS));
        mAgnusModeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::AGNUSMODE));
        mDeniseText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::DENISE));
        mDeniseRevisionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::DENISEREV));
        mPaulaText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::PAULA));
        mRTCText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::RTC));
        mBatteryClockText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::BATTCLOCK));

        mROMVersionText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::ROMVER));
        mROMSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::ROMSIZE));
    }
}
