//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "AOS/Identify/Library.hpp"
#include "Components/Core/Root.hpp"

#include "MUI/Group.hpp"
#include "MUI/List.hpp"

namespace Components
{
    class ExpansionsList : public Root<MUI::List>
    {
        MUI::List mComponent;

      public:
        ExpansionsList(const std::vector<AOS::Identify::ExpansionData> &expansions);

      protected:
        MUI::List &muiRoot() const
        {
            return const_cast<MUI::List &>(mComponent);
        }
    };
}