//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Root.hpp"

#include <proto/muimaster.h>

namespace Components
{
    void AbstractRoot::MuiAlert(const std::string &message) const
    {
        auto appObject = MUI::Notify(muiObject()).getApplicationObject();
#ifdef __MORPHOS__
        auto flags = 0;
#else
        auto flags = MUIV_Requester_Image_Error;
#endif
        MUI_Request(appObject, nullptr, flags, nullptr, (char *)"_Ok", (char *)message.c_str(), TAG_END);
    }

    void AbstractRoot::MuiWarning(const std::string &message) const
    {
        auto appObject = MUI::Notify(muiObject()).getApplicationObject();
#ifdef __MORPHOS__
        auto flags = 0;
#else
        auto flags = MUIV_Requester_Image_Warning;
#endif
        MUI_Request(appObject, nullptr, flags, nullptr, (char *)"_Ok", (char *)message.c_str(), TAG_END);
    }

    void AbstractRoot::MuiInfo(const std::string &message, const std::string &gadgets) const
    {
        auto appObject = MUI::Notify(muiObject()).getApplicationObject();
        MUI_Request(appObject, nullptr, 0, nullptr, (char *)gadgets.c_str(), (char *)message.c_str(), TAG_END);
    }

    long AbstractRoot::MuiRequest(const std::string &title, const std::string &message, const std::string &gadgets) const
    {
        auto appObject = MUI::Notify(muiObject()).getApplicationObject();
        return MUI_Request(appObject, nullptr, 0, (char *)title.c_str(), (char *)gadgets.c_str(), (char *)message.c_str(), TAG_END);
    }
}
