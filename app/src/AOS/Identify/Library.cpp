//
//  Git Desktop
//
//  (c) 2022-2024 TDolphin
//

#include "Library.hpp"

#include <libraries/identify.h>
#include <proto/identify.h>

namespace AOS::Identify
{

    std::vector<CpuInfo> Library::GetAllCPUs()
    {
        return { {
                     CpuType::MC68k,
                     IdHardware(IDHW_CPU, nullptr),
                     IdHardware(IDHW_CPUREV, nullptr),
                     IdHardware(IDHW_CPUCLOCK, nullptr),
                 },
                 {
                     CpuType::PowerPC,
                     IdHardware(IDHW_POWERPC, nullptr),
                     "",
                     IdHardware(IDHW_PPCCLOCK, nullptr),
                 } };
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
