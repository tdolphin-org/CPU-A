//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "AboutTab.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "ProgDefines.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    AboutTab::AboutTab()
      : mGoHomePageButton(MUIX_C MUIX_PH TDOLPHIN_WEBPAGE, TDOLPHIN_WEBPAGE, TDOLPHIN_WEBPAGE, 0)
      , mGoGitRepositoryButton(MUIX_C MUIX_PH GIT_REPOSITORY_URL, GIT_REPOSITORY_URL, GIT_REPOSITORY_URL, 0)
      , mComponent(MUI::GroupBuilder()
                       .tagFrame(MUI::Frame::Group)
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(MUI::TextBuilder().tagContents(Label::AboutContent).object())
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagChild(MUI::MakeObject::HSpace(-1))
                                     .tagChild(mGoHomePageButton)
                                     .tagChild(MUI::MakeObject::HSpace(-1))
                                     .object())
                       .tagChild(MUI::TextBuilder().tagContents(MUIX_C MUIX_PH TDOLPHIN_EMAIL).object())
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagChild(MUI::MakeObject::HSpace(-1))
                                     .tagChild(mGoGitRepositoryButton)
                                     .tagChild(MUI::MakeObject::HSpace(-1))
                                     .object())
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
    }
}
