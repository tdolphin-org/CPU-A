//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include <libraries/identify.h>

namespace AOS::Identify
{
    enum class IDFPU
    {
        NONE = IDFPU_NONE,
        MC68881 = IDFPU_68881,
        MC68882 = IDFPU_68882,
        MC68040 = IDFPU_68040,
        MC68060 = IDFPU_68060,
        FPGA = IDFPU_FPGA,
        EMU68 = IDFPU_EMU68,
    };
}
