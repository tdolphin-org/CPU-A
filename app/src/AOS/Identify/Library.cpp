//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Library.hpp"

#include <libraries/identify.h>
#include <proto/identify.h>

namespace AOS::Identify
{

    std::vector<CpuInfo> Library::GetAllCPUs()
    {
        return { CpuInfo { CpuType::MC68k,
                           { .m68k = GetCPU() },
                           IdHardware(IDHW_CPU, nullptr),
                           IdHardware(IDHW_CPUREV, nullptr),
                           IdHardware(IDHW_CPUCLOCK, nullptr),
                           {
                               std::string("FPU:") + IdHardware(IDHW_FPU, nullptr),
                               std::string("MMU:") + IdHardware(IDHW_MMU, nullptr),
                           } },
                 CpuInfo {
                     CpuType::PowerPC,
                     { .ppc = GetPowerPC() },
                     IdHardware(IDHW_POWERPC, nullptr),
                     "",
                     IdHardware(IDHW_PPCCLOCK, nullptr),
                     {},
                 } };
    }

    IDCPU Library::GetCPU() noexcept
    {
        return static_cast<IDCPU>(IdHardwareNum(IDHW_CPU, nullptr));
    }

    IDFPU Library::GetFPU() noexcept
    {
        return static_cast<IDFPU>(IdHardwareNum(IDHW_FPU, nullptr));
    }

    IDMMU Library::GetMMU() noexcept
    {
        return static_cast<IDMMU>(IdHardwareNum(IDHW_MMU, nullptr));
    }

    IDPPC Library::GetPowerPC() noexcept
    {
        return static_cast<IDPPC>(IdHardwareNum(IDHW_POWERPC, nullptr));
    }

    std::vector<Expansion> Library::GetAllExpansions() noexcept
    {
        std::vector<Expansion> expansions;

        struct ConfigDev *pConfigDev = nullptr;

        char manufacturerName[IDENTIFYBUFLEN], productName[IDENTIFYBUFLEN], productClass[IDENTIFYBUFLEN];

        while (!IdExpansionTags(IDTAG_ManufStr, (unsigned long)manufacturerName, IDTAG_ProdStr, (unsigned long)productName, IDTAG_ClassStr,
                                (unsigned long)productClass, IDTAG_Expansion, (unsigned long)&pConfigDev, TAG_DONE))
        {
            expansions.push_back({
                pConfigDev,
                manufacturerName,
                productName,
                productClass,
            });
        }

        return expansions;
    }

    std::string Library::libIdHardware(const enum IDHW idhw) noexcept
    {
        return IdHardware((ULONG)idhw, nullptr);
    }

    unsigned long Library::libIdHardwareNum(const enum IDHW idhw) noexcept
    {
        return IdHardwareNum((ULONG)idhw, nullptr);
    }
}
