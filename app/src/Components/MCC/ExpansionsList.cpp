//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "ExpansionsList.hpp"

#ifdef TRACE_CUSTOM_COMPONENTS
#include "amiga_std_light/iostream.hpp"
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
        auto list = MUI::ListBuilderTemplate<ExpansionsListBuilder, ActionRoot<MUI::List>>::object(sizeof(CustomObjectData));
        return list;
    }
}
