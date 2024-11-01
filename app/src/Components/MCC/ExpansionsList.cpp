//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "ExpansionsList.hpp"

#ifdef TRACE_CUSTOM_COMPONENTS
#include <iostream>
#endif

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "Components/DataType/ExpansionRef.hpp"
#include "MUI/Notifier/Notifier.hpp"

#include "SDI/SDI_compiler.h"
#include "SDI/SDI_hook.h"

unsigned long ConstructEntry(UNUSED struct IClass *cl, UNUSED Object *obj, UNUSED struct MUIP_List_Construct *msg)
{
    auto expansionRef = (ExpansionRef *)msg->entry;

    ExpansionRef *copy = (ExpansionRef *)AllocPooled(msg->pool, sizeof(ExpansionRef));
    if (copy != nullptr)
        *copy = *expansionRef;

    return (unsigned long)copy;
}

unsigned long DestructEntry(UNUSED struct IClass *cl, UNUSED Object *obj, UNUSED struct MUIP_List_Destruct *msg)
{
    auto expansionRef = (ExpansionRef *)msg->entry;
    if (expansionRef)
        FreePooled(msg->pool, (APTR)expansionRef, sizeof(ExpansionRef));

    return 0;
}

unsigned long DisplayEntry(UNUSED struct IClass *cl, UNUSED Object *obj, UNUSED struct MUIP_List_Display *msg)
{
    static ExpansionRef displayExpansionRef;
    auto *array = msg->array;
    std::string message;

    if (msg->entry)
    {
        auto expansionRef = (ExpansionRef *)msg->entry;
        if (expansionRef)
            displayExpansionRef = *expansionRef;

        *array++ = displayExpansionRef.product;
        *array++ = displayExpansionRef.productClass;
        *array = displayExpansionRef.manufacturer;
    }
    else
    {
        *array++ = MUIX_C "Product";
        *array++ = MUIX_C "Class";
        *array = MUIX_C "Manufacturer";
    }

    return 0;
}

DISPATCHER(ExpansionsListDispatcherFunc)
{
    // Be careful with std::cout, when here is some "debug" info !!!
    // It causes that MUI interface hangs during "drag&drop"!
    // std::cout << __PRETTY_FUNCTION__ << std::hex << "MethodID: 0x" << msg->MethodID << std::endl;

    switch (msg->MethodID)
    {
        case MUIM_List_Construct:
            return ConstructEntry(cl, obj, (MUIP_List_Construct *)msg);
        case MUIM_List_Destruct:
            return DestructEntry(cl, obj, (MUIP_List_Destruct *)msg);
        case MUIM_List_Display:
            return DisplayEntry(cl, obj, (MUIP_List_Display *)msg);
        default:
        {
            auto dispatchMethodResult = Components::MCC::dispatchMethod(msg->MethodID, cl, obj, msg);
            if (dispatchMethodResult.dispatchResult)
                return dispatchMethodResult.methodResult;
        }
    }

    return DoSuperMethodA(cl, obj, msg);
}

namespace Components::MCC
{
    ExpansionsListBuilder::ExpansionsListBuilder()
      : MUI::ListBuilderTemplate<ExpansionsListBuilder, ActionRoot<MUI::List>>("ExpansionsList")
    {
    }

    ActionRoot<MUI::List> ExpansionsListBuilder::object()
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        auto list = MUI::ListBuilderTemplate<ExpansionsListBuilder, ActionRoot<MUI::List>>::object(sizeof(CustomObjectData),
                                                                                                   ENTRY(ExpansionsListDispatcherFunc));
        return list;
    }

    ActionRoot<MUI::List> ExpansionsListBuilder::object(OnActiveEntryDispatcher &dispatcher)
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        PushTag(MUIA_ActionDispatcher, (void *)&dispatcher);

        auto list = MUI::ListBuilderTemplate<ExpansionsListBuilder, ActionRoot<MUI::List>>::object(sizeof(CustomObjectData),
                                                                                                   ENTRY(ExpansionsListDispatcherFunc));

        // any entry selected
        // -> call dispatcher method
        MUI::Notifier::from(list).onActiveEveryTime().notifySelf().method(MUIM_ActionOnActiveEntry);

        return list;
    }
}
