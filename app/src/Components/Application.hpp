//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "AppWindow.hpp"
#include "Components/Core/Root.hpp"
#include "MUI/Application.hpp"

namespace Components
{
    class Application : public Root<MUI::Application>
    {
        AppWindow mAppWindow;
        MUI::Application mComponent;

      public:
        Application();

        void RegisterEvents();

      protected:
        MUI::Application &muiRoot() const
        {
            return (MUI::Application &)mComponent;
        }
    };
}
