//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "MemoryTab.hpp"

#include "AOS/Identify/Library.hpp"

namespace Components
{
    MemoryTab::MemoryTab()
      : mMainboardRAMAccessTimeText(ValueText("Main board RAM access time (unit ns)"))
      , mMainboardRAMWidthText(ValueText("Main board RAM width (bit)"))
      , mMainboardRAMCASModeText(ValueText("Main board RAM CAS mode"))
      , mMainboardRAMBandwidthText(ValueText("Main board RAM bandwidth"))
      , mPlainChipRAMSizeText(ValueText("Plain Chip RAM"))
      , mPlainFastRAMSizeText(ValueText("Plain Fast RAM"))
      , mPlainSlowRAMSizeText(ValueText("Plain Slow RAM"))
      , mVMMChipRamSizeText(ValueText("VMM Chip RAM"))
      , mVMMFastRamSizeText(ValueText("VMM Fast RAM"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Main board RAM")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Access time (ns)"))
                                     .tagChild(mMainboardRAMAccessTimeText)
                                     .tagChild(LabelText(MUIX_R "Width (bit)"))
                                     .tagChild(mMainboardRAMWidthText)
                                     .tagChild(LabelText(MUIX_R "CAS mode"))
                                     .tagChild(mMainboardRAMCASModeText)
                                     .tagChild(LabelText(MUIX_R "Bandwidth"))
                                     .tagChild(mMainboardRAMBandwidthText)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Chip/Fast/Slow")
                                     .tagColumns(6)
                                     .tagChild(LabelText(MUIX_R "Chip RAM"))
                                     .tagChild(mPlainChipRAMSizeText)
                                     .tagChild(LabelText(MUIX_R "Fast RAM"))
                                     .tagChild(mPlainFastRAMSizeText)
                                     .tagChild(LabelText(MUIX_R "Slow RAM"))
                                     .tagChild(mPlainSlowRAMSizeText)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Virtual Memory")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Chip RAM"))
                                     .tagChild(mVMMChipRamSizeText)
                                     .tagChild(LabelText(MUIX_R "Fast RAM"))
                                     .tagChild(mVMMFastRamSizeText)
                                     .object())
                       .object())
    {
        mMainboardRAMAccessTimeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::RAMACCESS));
        mMainboardRAMWidthText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::RAMWIDTH));
        mMainboardRAMCASModeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::RAMCAS));
        mMainboardRAMBandwidthText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::RAMBANDWIDTH));
        mPlainChipRAMSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::PLNCHIPRAM));
        mPlainFastRAMSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::PLNFASTRAM));
        mPlainSlowRAMSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::SLOWRAM));
        mVMMChipRamSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::VMMCHIPRAM));
        mVMMFastRamSizeText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::VMMFASTRAM));
    }
}
