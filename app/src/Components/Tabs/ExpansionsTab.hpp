//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Expansions/ExpansionsList.hpp"
#include "Components/Tabs/TabsContainer.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class ExpansionsTab : public Root<MUI::Group>
    {
        ExpansionsList mNativeExpansionsList;
        ExpansionsList mPCIExpansionsList;
        MUI::Group mPCIExpansionsGroup;

        TabsContainer mComponent;

      public:
        ExpansionsTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return mComponent;
        }
    };
}