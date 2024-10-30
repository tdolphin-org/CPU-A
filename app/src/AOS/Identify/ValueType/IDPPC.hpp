//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include <libraries/identify.h>

namespace AOS::Identify
{
    enum class IDPPC
    {
        NONE = IDPPC_NONE,
        OTHER = IDPPC_OTHER,
        PPC602 = IDPPC_602,
        PPC603 = IDPPC_603,
        PPC603E = IDPPC_603E,
        PPC603P = IDPPC_603P,
        PPC604 = IDPPC_604,
        PPC604E = IDPPC_604E,
        PPC620 = IDPPC_620,
    };
}
