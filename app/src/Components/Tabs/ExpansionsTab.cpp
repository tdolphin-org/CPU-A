//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "ExpansionsTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    ExpansionsTab::ExpansionsTab()
      : mExpansionsList(MUI::ListBuilder().tagConstructHookString().tagDestructHookString().tagFrame(MUI::Frame::ReadList).object())
      , mComponent(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLLabel("Expansions")).tagChild(mExpansionsList).object())
    {
        auto expansions = AOS::Identify::Library::GetAllExpansions();
        for (auto &expansion : expansions)
            mExpansionsList.InsertSingleBottom(expansion.productName);
    }
}
