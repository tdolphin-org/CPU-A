//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Core/Root.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"
#include "Tabs/Content.hpp"

namespace Components
{
    class AppWindow : public Root<MUI::Window>
    {
        Content mContent;
        MUI::Area mToolsButton;
        MUI::Area mCloseButton;
        MUI::Window mComponent;

      public:
        AppWindow();

        void RegisterEvents();

      protected:
        MUI::Window &muiRoot() const
        {
            return (MUI::Window &)mComponent;
        }
    };
}
