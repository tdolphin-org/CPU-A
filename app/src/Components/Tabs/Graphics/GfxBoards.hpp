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
    class GfxBoards : public Root<MUI::Group>, public TabBase
    {
        MUI::Group mComponent;

      public:
        GfxBoards();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
