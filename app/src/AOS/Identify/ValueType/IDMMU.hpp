//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include <libraries/identify.h>

namespace AOS::Identify
{
    enum class IDMMU
    {
        NONE = IDMMU_NONE,
        MC68851 = IDMMU_68851,
        MC68030 = IDMMU_68030,
        MC68040 = IDMMU_68040,
        MC68060 = IDMMU_68060,
        FPGA = IDMMU_FPGA,
        EMU68 = IDMMU_EMU68,
    };
}
