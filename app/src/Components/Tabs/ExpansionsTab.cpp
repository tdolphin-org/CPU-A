//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "ExpansionsTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "AppContext.hpp"
#include "Components/DataType/ExpansionRef.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Text.hpp"
#include "TextResources/Errors.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    ExpansionsTab::ExpansionsTab()
      : mNativeExpansionsList(AppContext::instance().getExpansions())
      , mPCIExpansionsList(AppContext::instance().getPCIExpansions())
      , mPCIExpansionsGroup(MUI::GroupBuilder()
                                .tagPageMode(true)
                                .tagChild(mPCIExpansionsList)
                                .tagChild(MUI::GroupBuilder()
                                              .tagChild(MUI::MakeObject::HVSpace())
                                              .tagChild(MUI::MakeObject::CLabel1([&]() -> const char * {
                                                  switch (AppContext::instance().getPCIExpansionsResultCode())
                                                  {
                                                      case AOS::Identify::PCIExpansionsResultCode::NoPCILib:
                                                          return Error::NoPCILib;
                                                      case AOS::Identify::PCIExpansionsResultCode::NoPCIDb:
                                                          return Error::NoPCIDb;
                                                      case AOS::Identify::PCIExpansionsResultCode::BadPCIDb:
                                                          return Error::BadPCIDb;
                                                      case AOS::Identify::PCIExpansionsResultCode::Missing45:
                                                          return Error::Missing45;
                                                          //   case AOS::Identify::PCIExpansionsResultCode::Success:
                                                          //       return Error::Success;
                                                  }
                                                  return Error::UnknownError;
                                              }()))
                                              .tagChild(MUI::MakeObject::HVSpace())
                                              .object())
                                .object())
      , mComponent({
            { Label::NativeExpansions, mNativeExpansionsList },
            { Label::PCIExpansions, mPCIExpansionsGroup },
        })
    {
        if (AppContext::instance().getPCIExpansionsResultCode() == AOS::Identify::PCIExpansionsResultCode::Success)
            mPCIExpansionsGroup.setActivePageFirst();
        else
            mPCIExpansionsGroup.setActivePageLast();
    }
}
