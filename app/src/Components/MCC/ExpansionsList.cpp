//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
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

// struct Towar *towar reg(a1), APTR mempool reg(a2)
HOOKPROTO(ConstructEntry, unsigned long, APTR pool, ExpansionRef *expansionRef)
{
    ExpansionRef *copy = (ExpansionRef *)AllocPooled(pool, sizeof(ExpansionRef));
    if (copy != nullptr)
        *copy = *expansionRef;

    return (unsigned long)copy;
}

HOOKPROTO(DestructEntry, unsigned long, APTR pool, ExpansionRef *expansionRef)
{
    if (expansionRef)
        FreePooled(pool, (APTR)expansionRef, sizeof(ExpansionRef));

    return 0;
}

HOOKPROTO(DisplayEntry, unsigned long, char **array, ExpansionRef *expansionRef)
{
    static ExpansionRef displayExpansionRef;
    static auto *product = MUIX_C "[ID] Product";
    static auto *productClass = MUIX_C "Class";
    static auto *manufacturer = MUIX_C "[ID] Manufacturer";
    static auto *additionalInfo = MUIX_C "Info";

    if (expansionRef)
    {
        displayExpansionRef = *expansionRef;

        *array++ = displayExpansionRef.product;
        *array++ = displayExpansionRef.productClass;
        *array++ = displayExpansionRef.manufacturer;
        *array = displayExpansionRef.additionalInfo;
    }
    else
    {
        *array++ = (char *)product;
        *array++ = (char *)productClass;
        *array++ = (char *)manufacturer;
        *array = (char *)additionalInfo;
    }

    return 0;
}

typedef unsigned long (*HOOKFUNC_)();

struct Hook ConstructHook = { { nullptr, nullptr }, (HOOKFUNC_)ConstructEntry, nullptr, nullptr };
struct Hook DestructHook = { { nullptr, nullptr }, (HOOKFUNC_)DestructEntry, nullptr, nullptr };
struct Hook DisplayHook = { { nullptr, nullptr }, (HOOKFUNC_)DisplayEntry, nullptr, nullptr };

DISPATCHER(ExpansionsListDispatcherFunc)
{
    // Be careful with std::cout, when here is some "debug" info !!!
    // It causes that MUI interface hangs during "drag&drop"!
    // std::cout << __PRETTY_FUNCTION__ << std::hex << "MethodID: 0x" << msg->MethodID << std::endl;

    switch (msg->MethodID)
    {
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
        PushTag(MUIA_List_ConstructHook, &ConstructHook);
        PushTag(MUIA_List_DestructHook, &DestructHook);
        PushTag(MUIA_List_DisplayHook, &DisplayHook);
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
