//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "CPUSpec.hpp"

// micro sign: \xB5
// use u instead

namespace DataInfo
{
    const std::map<AOS::Identify::IDCPU, CPUSpec> cpuMC68k2spec {
        { AOS::Identify::IDCPU::MC68000, { "Motorola", "68000", "3.3 V, 5 V", "2.0-3.5 um", "1979", "~0.7-1.5 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68010, { "Motorola", "68010", "5V", "2.0 um", "1982", "~1-2 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68020, { "Motorola", "68020", "5V", "1.5 um", "1984", "~2-4 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68030, { "Motorola", "68030", "5V", "1.0 um", "1987", "~2-5 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68EC030, { "Motorola", "68EC030", "5V", "1.0 um", "1987", "~2-5 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68040, { "Motorola", "68040", "5 V", "0.8 um", "1990", "~3.5-8 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68LC040, { "Motorola", "68LC040", "5 V", "0.8 um", "1990", "~3.5-8 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68060, { "Motorola / Freescale", "68060", "3.3 V", "0.42-0.6 um", "1993", "~2-7 W", 1, 1 } },
        { AOS::Identify::IDCPU::MC68LC060, { "Motorola / Freescale", "68LC060", "3.3 V", "0.42-0.6 um", "1993", "~2-7 W", 1, 1 } },
        { AOS::Identify::IDCPU::FPGA, { "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", 0, 0 } },
        { AOS::Identify::IDCPU::EMU68, { "Arm", "N/A", "N/A", "N/A", "N/A", "N/A", 0, 0 } },
    };

    const std::map<AOS::Identify::IDPPC, CPUSpec> cpuPPC2spec {
        { AOS::Identify::IDPPC::PPC602, { "Motorola/IBM", "602", "3.3 V", "0.5 um", "February 1995", "~1.2 W", 1, 1 } },
        { AOS::Identify::IDPPC::PPC603, { "Motorola/IBM", "603", "3.3 V", "0.5 um", "1994", "~2.2-3.5 W", 1, 1 } },
        { AOS::Identify::IDPPC::PPC603E, { "Motorola/IBM", "603e", "2.5 V, 3.3 V", "0.35-0.5 um", "April 1996", "~6 W", 1, 1 } },
        { AOS::Identify::IDPPC::PPC603P, { "Motorola/IBM", "603p", "2.5 V", "0.35 um", "?", "~4-5 W", 1, 1 } },
        { AOS::Identify::IDPPC::PPC604, { "Motorola/IBM", "604", " 3.3 V", "0.5 um", "April 1994", "~14-17 W", 1, 1 } },
        { AOS::Identify::IDPPC::PPC604E, { "Motorola/IBM", "604e", " 2.5 V", "0.35 um", "1996", "~16-18 W", 1, 1 } },
        { AOS::Identify::IDPPC::PPC620, { "Motorola", "620", "3.3 V", "0.35-0.5 um", "1997", "~30 W", 1, 1 } },
    };
}
