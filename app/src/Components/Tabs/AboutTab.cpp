//
//  CPU-A
//
//  (c) 2024-2026 TDolphin
//

#include "AboutTab.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "ProgDefines.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    AboutTab::AboutTab()
      : mGoHomePageButton(MUIX_C MUIX_PH TDOLPHIN_WEBPAGE, TDOLPHIN_WEBPAGE, TDOLPHIN_WEBPAGE, 0)
      , mMailToButton(MUIX_C MUIX_PH TDOLPHIN_EMAIL, TDOLPHIN_EMAIL, "mailto:" TDOLPHIN_EMAIL, 0)
      , mGoGitRepositoryButton(MUIX_C MUIX_PH GIT_REPOSITORY_URL, GIT_REPOSITORY_URL, GIT_REPOSITORY_URL, 0)
      , mComponent(MUI::GroupBuilder()
                       .tagFrame(MUI::Frame::Group)
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(MUI::TextBuilder().tagContents(Label::AboutContent).object())
                       .tagChild(MUI::MakeObject::HCenter(mGoHomePageButton))
                       .tagChild(MUI::MakeObject::HCenter(mMailToButton))
                       .tagChild(MUI::MakeObject::HCenter(mGoGitRepositoryButton))
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
    }
}
