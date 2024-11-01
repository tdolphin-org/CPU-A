//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "App.hpp"

#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Core/CustomClassManager.hpp"

#include <proto/alib.h>
#include <proto/exec.h>

using namespace std;

AppCore::AppCore() { }

void AppCore::Run()
{
    // special class, on destructor Dispose all custom classes
    MUI::CustomClassesLifeTimeScope customClassesLifeTimeScope;

    // application scope
    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope application(mApplication);

    mApplication.RegisterEvents();

    auto appWindow = MUI::ApplicationContext::instance().getAppWindow();

    // open window on constructor, close on destructor
    MUI::WindowScope window(appWindow);

    // main application loop
    ULONG signals = 0;
    while (DoMethod(mApplication.muiObject(), MUIM_Application_NewInput, &signals) != MUIV_Application_ReturnID_Quit)
    {
        if (signals)
        {
            signals = Wait(signals | SIGBREAKF_CTRL_C);
            if (signals & SIGBREAKF_CTRL_C)
                break;
        }
    }
}
