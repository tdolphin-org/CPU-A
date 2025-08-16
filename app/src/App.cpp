//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "App.hpp"

#include "Components/Application.hpp"
#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Core/CustomClassManager.hpp"

#include <proto/alib.h>
#include <proto/exec.h>

#ifdef TRACE
#include "amiga_std_light/iostream.hpp"
#endif

AppCore::AppCore()
  : openUrlBaseScope(true)
  , picasso96BaseScope(true)
  , cybergraphicsBaseScope(true)
{
}

void AppCore::Run()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    // special class, on destructor Dispose all custom classes
    MUI::CustomClassesLifeTimeScope customClassesLifeTimeScope;

    Components::Application muiApplication;

    // application scope
    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope application(muiApplication);

    muiApplication.RegisterEvents();

    auto appWindow = MUI::ApplicationContext::instance().getAppWindow();

    // open window on constructor, close on destructor
    MUI::WindowScope window(appWindow);

    // main application loop
    uint32_t signals = 0;
    while (DoMethod(muiApplication.muiObject(), MUIM_Application_NewInput, &signals) != (unsigned long)MUIV_Application_ReturnID_Quit)
    {
        if (signals)
        {
            signals = Wait(signals | SIGBREAKF_CTRL_C);
            if (signals & SIGBREAKF_CTRL_C)
                break;
        }
    }
}
