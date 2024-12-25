//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "BoardsBase.hpp"
#include "Components/Buttons/GfxChipSpecButton.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class CGXBoards : public BoardsBase
    {
        std::vector<GfxChipSpecButton *> mGfxChipSpecButtons;

      public:
        CGXBoards();
        virtual ~CGXBoards();
    };
}
