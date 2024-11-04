//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Group.hpp"
#include "MUI/Title.hpp"

#include <string>
#include <vector>

namespace Components
{
    class TabsContainer : public Root<MUI::Group>
    {
        MUI::Title mTabsTitle;
        MUI::Group mComponent;

      public:
        explicit TabsContainer(const std::vector<std::pair<std::string, MUI::Area &>> &tabs);

      protected:
        MUI::Group &muiRoot() const
        {
            return (MUI::Group &)mComponent;
        }
    };
}
