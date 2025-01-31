//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "AppWindow.hpp"

#include "IDs.hpp"
#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Group.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"

namespace Components
{
    AppWindow::AppWindow()
      : mContent()
      , mCloseButton(MUI::MakeObject::SimpleButton("_Close"))
      , mComponent(MUI::WindowBuilder()
                       .tagTitle(APP_NAME)
                       .tagScreenTitle(SCREEN_TITLE)
                       .tagID(WindowID::AppWindow)
                       .tagWidth(600)
                       .tagHeight(240)
                       .tagAltWidth(1024)
                       .tagAltHeight(600)
                       .tagRootObject(MUI::GroupBuilder()
                                          .tagChild(mContent)
                                          .tagChild(MUI::GroupBuilder()
                                                        .horizontal()
                                                        .tagChild(MUI::TextBuilder()
                                                                      .tagContents(MUIX_PH MUIX_B APP_NAME MUIX_N MUIX_PT
                                                                                   " ver. " APP_VERSION " " APP_DATE)
                                                                      .object())
                                                        .tagChild(MUI::MakeObject::HVSpace())
                                                        .tagChild(mCloseButton)
                                                        .object())
                                          .object())
                       .object())
    {
        mCloseButton.setCycleChain();
    }

    void AppWindow::RegisterEvents()
    {
        auto app = MUI::ApplicationContext::instance().getApplication();

        MUI::Notifier::from(MUI::Area(mCloseButton)).onPressed(false).notifyObject(app).returnIDQuit();
    }
}
