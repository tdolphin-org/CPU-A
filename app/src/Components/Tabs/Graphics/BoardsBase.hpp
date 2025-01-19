//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class BoardsBase : public Root<MUI::Group>
    {
      protected:
        MUI::Group mComponent;

      public:
        BoardsBase(const std::string &frameTitle);
        virtual ~BoardsBase() = default;

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
