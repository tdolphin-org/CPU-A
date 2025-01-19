//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "GfxChipSpecButton.hpp"

#include "WindowManager.hpp"

namespace Components
{
    GfxChipSpecButton::GfxChipSpecButton(const std::vector<DataInfo::GfxChipID> &chips)
      : BasicButton("?", "Show more info about this gfx chip(s)", 0)
      , mChips(chips)
    {
    }

    unsigned long GfxChipSpecButton::OnClick()
    {
        WindowManager::instance().getGfxChipSpecWindow().Open(mChips);
        return 0;
    }
}
