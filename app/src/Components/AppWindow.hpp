//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Content.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class AppWindow : public Root<MUI::Window>
    {
        std::string mUsedIdentifyVersion;
        Content mContent;
        MUI::Area mExitButton;
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
