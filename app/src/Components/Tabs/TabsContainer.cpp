//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "TabsContainer.hpp"

#include "MUI/Text.hpp"

namespace Components
{
    TabsContainer::TabsContainer(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
      : mTabsTitle(MUI::TitleBuilder().object())
      , mComponent(MUI::GroupBuilder()
#ifdef __MORPHOS__
                       .tagPageMode()
                       .tagBackground(MUI::ImageOrBackground::RegisterBack)
                       .tagFrame(MUI::Frame::Register)
#endif
                       .tagCycleChain()
                       .tagChild(mTabsTitle)
                       .object())
    {
        for (const auto &tab : tabs)
            mTabsTitle.AddTail(MUI::TextBuilder().tagContents(tab.first).object());

        for (const auto &tab : tabs)
            mComponent.AddTail(tab.second);
    }
}
