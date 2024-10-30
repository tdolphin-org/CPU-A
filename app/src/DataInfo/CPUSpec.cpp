//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "CPUSpec.hpp"

namespace DataInfo
{
    const std::map<AOS::Identify::IDCPU, CPUSpec> cpuMC68k2spec {
        { AOS::Identify::IDCPU::MC68000, { "Motorola", "68000", "3.3 V, 5 V", "2.0-3.5 \xB5m", "1979", "~0.7-1.5 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68010, { "Motorola", "68010", "5V", "2.0 \xB5m", "1982", "~1-2 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68020, { "Motorola", "68020", "5V", "1.5 \xB5m", "1984", "~2-4 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68030, { "Motorola", "68030", "5V", "1.0 \xB5m", "1987", "~2-5 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68EC030, { "Motorola", "68EC030", "5V", "1.0 \xB5m", "1987", "~2-5 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68040, { "Motorola", "68040", "5 V", "0.8 \xB5m", "1990", "~3.5-8 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68LC040, { "Motorola", "68LC040", "5 V", "0.8 \xB5m", "1990", "~3.5-8 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68060, { "Motorola / Freescale", "68060", "3.3 V", "0.42-0.6 \xB5m", "1993", "~2-7 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68LC060, { "Motorola / Freescale", "68LC060", "3.3 V", "0.42-0.6 \xB5m", "1993", "~2-7 W", 1, 1 } },
        { AOS::Identify::IDCPU::FPGA, { "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", 0, 0 } },
        { AOS::Identify::IDCPU::EMU68, { "Arm", "N/A", "N/A", "N/A", "N/A", "N/A", 0, 0 } },
    };
}
