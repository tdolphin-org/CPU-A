//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "../Core/Root.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class MainboardTab : public Root<MUI::Group>
    {
        MUI::Group mComponent;

      public:
        MainboardTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}