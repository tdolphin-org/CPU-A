//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include <libraries/identify.h>

namespace AOS::Identify
{
    enum class IDCPU
    {
        MC68000 = IDCPU_68000,
        MC68010 = IDCPU_68010,
        MC68020 = IDCPU_68020,
        MC68030 = IDCPU_68030,
        MC68EC030 = IDCPU_68EC030,
        MC68040 = IDCPU_68040,
        MC68LC040 = IDCPU_68LC040,
        MC68060 = IDCPU_68060,
        MC68LC060 = IDCPU_68LC060,
        FPGA = IDCPU_FPGA,
        EMU68 = IDCPU_EMU68,
    };
}
