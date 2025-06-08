//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "ExpansionsTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "AppContext.hpp"
#include "Components/DataType/ExpansionRef.hpp"
#include "TextResources/Labels.hpp"

#include <iomanip>
#include <sstream>

namespace Components
{
    ExpansionsTab::ExpansionsTab()
      : mNativeExpansionsList(AppContext::instance().getExpansions())
      , mPciExpansionsList(AppContext::instance().getPciExpansions())
      , mComponent({
            { Label::NativeExpansions, mNativeExpansionsList },
            { Label::PciExpansions, mPciExpansionsList },
        })
    {
    }
}
