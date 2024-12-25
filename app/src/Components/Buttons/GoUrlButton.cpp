//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "GoUrlButton.hpp"

#include "AOS/OpenURL/Library.hpp"
#include "AppContext.hpp"
#include "ProgDefines.hpp"

namespace Components
{
    GoUrlButton::GoUrlButton(const std::string &label, const std::string &shortHelp, const std::string &url, const long weight)
      : BasicButton(label, shortHelp, weight)
      , mUrl(url)
    {
#ifdef MUIA_PointerType
        muiRoot().setPointerType(MUI::PointerType::Link);
#endif
    }

    unsigned long GoUrlButton::OnClick()
    {
        if (AppContext::instance().getOpenURLBase().isOpen() && !mUrl.empty())
            AOS::OpenURL::Library::libOpen(mUrl);

        return 0;
    }
}
