//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"
#include "MUI/List.hpp"

namespace Components
{
    class ExpansionsTab : public Root<MUI::Group>, public TabBase
    {
        MUI::List mExpansionsList;

        MUI::Group mComponent;

      public:
        ExpansionsTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}