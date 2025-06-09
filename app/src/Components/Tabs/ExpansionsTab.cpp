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
      , mPciExpansionsList(AppContext::instance().getPciExpansions())
      , mPciExpansionsGroup(MUI::GroupBuilder()
                                .tagPageMode(true)
                                .tagChild(mPciExpansionsList)
                                .tagChild(MUI::GroupBuilder()
                                              .tagChild(MUI::MakeObject::HVSpace())
                                              .tagChild(MUI::MakeObject::CLabel1([&]() -> const char * {
                                                  switch (AppContext::instance().getPciExpansionsResultCode())
                                                  {
                                                      case AOS::Identify::PciExpansionsResultCode::NoPciLib:
                                                          return Error::NoPciLib;
                                                      case AOS::Identify::PciExpansionsResultCode::NoPciDb:
                                                          return Error::NoPciDb;
                                                      case AOS::Identify::PciExpansionsResultCode::BadPciDb:
                                                          return Error::BadPciDb;
                                                      case AOS::Identify::PciExpansionsResultCode::Missing45:
                                                          return Error::Missing45;
                                                  }
                                                  return Error::UnknownError;
                                              }()))
                                              .tagChild(MUI::MakeObject::HVSpace())
                                              .object())
                                .object())
      , mComponent({
            { Label::NativeExpansions, mNativeExpansionsList },
            { Label::PciExpansions, mPciExpansionsGroup },
        })
    {
        if (AppContext::instance().getPciExpansionsResultCode() == AOS::Identify::PciExpansionsResultCode::Success)
            mPciExpansionsGroup.setActivePageFirst();
        else
            mPciExpansionsGroup.setActivePageLast();
    }
}
