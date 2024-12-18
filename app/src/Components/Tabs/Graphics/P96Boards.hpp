//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/Tabs/TabBase.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class P96Boards : public Root<MUI::Group>, public TabBase
    {
        MUI::Group mComponent;

      public:
        P96Boards();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
