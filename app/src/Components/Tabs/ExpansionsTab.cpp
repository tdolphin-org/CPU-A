//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "ExpansionsTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "Components/DataType/ExpansionRef.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    const char *ExpansionsTab::titles[] = { MUIX_C "[ID] Product", MUIX_C "Class", MUIX_C "[ID] Manufacturer", MUIX_C "Info", nullptr };

    ExpansionsTab::ExpansionsTab()
      : mExpansionsList(MCC::ExpansionsListBuilder().tagFormat("BAR,BAR,BAR,").tagTitleArray(titles).tagFrame(MUI::Frame::Group).object())
      , mComponent(MUI::GroupBuilder().vertical().tagChild(mExpansionsList).object())
    {
        auto expansions = AOS::Identify::Library::GetExpansions();
        for (auto &expansion : expansions)
        {
            ExpansionRef expansionRef { expansion };
            mExpansionsList.InsertSingleBottom(&expansionRef);
        }
    }
}
