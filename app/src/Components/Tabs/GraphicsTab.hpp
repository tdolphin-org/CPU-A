
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
    class GraphicsTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mGfxSystemText;
        MUI::Group mGraphicsCards;

        MUI::Group mComponent;

      public:
        GraphicsTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
