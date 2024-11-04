
//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class AboutTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Group mComponent;

      public:
        AboutTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
