//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "Components/MCC/Core/ActionRoot.hpp"
#include "MUI/List.hpp"

namespace Components::MCC
{
    class ExpansionsListBuilder : public MUI::ListBuilderTemplate<ExpansionsListBuilder, ActionRoot<MUI::List>>
    {
      public:
        ExpansionsListBuilder();

        ActionRoot<MUI::List> object();
    };
}
