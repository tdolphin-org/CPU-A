//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Library.hpp"

#include <iomanip>
#include <libraries/identify.h>
#include <proto/identify.h>
#include <set>
#include <sstream>

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
                               std::string("FPU:") + IdHardware(IDHW_FPU, nullptr) +
                                   []() {
                                       std::string fpuClock = IdHardware(IDHW_FPUCLOCK, nullptr);
                                       return fpuClock == "N/A" ? "" : "@" + fpuClock;
                                   }(),
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

    std::vector<Expansion> Library::GetExpansions(const enum ClassID filterByClassId /*= ClassID::NONE*/) noexcept
    {
        std::vector<Expansion> expansions;

        std::set<int> ramClassIds { IDCID_TURBORAM, IDCID_GFXRAM, IDCID_HDRAM, IDCID_IDEHDRAM,   IDCID_RAMSCSIHD,
                                    IDCID_RAM,      IDCID_RAMFPU, IDCID_RAM32, IDCID_TURBOANDRAM };

        ConfigDev *pConfigDev = nullptr;

        char manufacturerName[IDENTIFYBUFLEN], productName[IDENTIFYBUFLEN], productClass[IDENTIFYBUFLEN];
        UWORD manufacturerId = 0;
        UBYTE productId = 0;
        ULONG classId = 0;

        while (!IdExpansionTags(IDTAG_ManufID, (unsigned long)&manufacturerId, IDTAG_ManufStr, (unsigned long)manufacturerName,
                                IDTAG_ProdID, (unsigned long)&productId, IDTAG_ProdStr, (unsigned long)productName, IDTAG_ClassStr,
                                (unsigned long)productClass, IDTAG_ClassID, (unsigned long)&classId, IDTAG_Expansion,
                                (unsigned long)&pConfigDev, TAG_DONE))
        {
            std::string additionalInfo;
            if (pConfigDev != nullptr)
            {
                if (filterByClassId != ClassID::NONE && classId != (int)filterByClassId)
                    continue;

                manufacturerId = pConfigDev->cd_Rom.er_Manufacturer;
                productId = pConfigDev->cd_Rom.er_Product;

                if (ramClassIds.find(classId) != ramClassIds.end())
                {
                    if (pConfigDev->cd_BoardSize % (1024 * 1024) == 0)
                        additionalInfo = std::to_string(pConfigDev->cd_BoardSize / (1024 * 1024)) + " MiB RAM";
                    else if (pConfigDev->cd_BoardSize % 1024 == 0)
                        additionalInfo = std::to_string(pConfigDev->cd_BoardSize / 1024) + " KiB RAM";
                    else
                        additionalInfo = std::to_string(pConfigDev->cd_BoardSize) + " Bytes RAM";
                }
            }

            std::stringstream manufacturerIdStream, productIdStream;
            if (manufacturerId != 0)
                manufacturerIdStream << "[0x" << std::setfill('0') << std::setw(4) << std::hex << manufacturerId << "] ";
            if (productId != 0)
                productIdStream << "[0x" << std::setfill('0') << std::setw(2) << std::hex << (int)productId << "] ";

            expansions.push_back({
                pConfigDev,
                manufacturerIdStream.str(),
                manufacturerName,
                productIdStream.str(),
                productName,
                productClass,
                additionalInfo,
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
