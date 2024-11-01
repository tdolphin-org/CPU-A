//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/MCC/Core/Dispatcher/OnActiveEntryDispatcher.hpp"
#include "MUI/List.hpp"

namespace Components::MCC
{
    class ExpansionsListBuilder : public MUI::ListBuilderTemplate<ExpansionsListBuilder, ActionRoot<MUI::List>>
    {
      public:
        ExpansionsListBuilder();

        ActionRoot<MUI::List> object();
        ActionRoot<MUI::List> object(OnActiveEntryDispatcher &dispatcher);
    };
}
