//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Application.hpp"

#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"

namespace Components
{
    Application::Application()
      : mComponent(MUI::ApplicationBuilder()
                       .tagAuthor(AUTHORS)
                       .tagBase(CMD_NAME)
                       .tagCopyright(APP_TDOLPHIN_COPYRIGHTS)
                       .tagDescription(APP_DESCRIPTION)
                       .tagTitle(APP_NAME)
                       .tagVersion(AMIGAOS_VER_PREFIX " " CMD_NAME " " APP_VERSION " " APP_DATE)
                       .tagWindow(mAppWindow)
                       .object())
    {
    }

    void Application::RegisterEvents()
    {
        MUI::Notifier::from(mAppWindow).onCloseRequest(true).notifyObject(mComponent).returnIDQuit();

        mAppWindow.RegisterEvents();
    }
}
