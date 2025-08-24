//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "BoardsBase.hpp"
#include "Components/Buttons/GfxChipSpecButton.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class P96Boards : public BoardsBase
    {
        std::vector<GfxChipSpecButton *> mGfxChipSpecButtons;

      public:
        P96Boards();
    };
}
