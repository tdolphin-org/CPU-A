//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "ValueType/ClassID.hpp"
#include "ValueType/IDCPU.hpp"
#include "ValueType/IDFPU.hpp"
#include "ValueType/IDHW.hpp"
#include "ValueType/IDMMU.hpp"
#include "ValueType/IDPPC.hpp"

#include <libraries/configvars.h>
#include <string>
#include <vector>

namespace AOS::Identify
{
    enum class CpuType
    {
        MC68k,
        PowerPC,
    };

    struct CpuInfo
    {
        CpuType type;
        union
        {
            enum IDCPU m68k;
            enum IDPPC ppc;
        } model;
        std::string modelName;
        std::string revision;
        std::string clock;
        std::vector<std::string> additionalUnits;
    };

    struct Expansion
    {
        ConfigDev *configDev;
        std::string manufacturerId;
        std::string manufacturer;
        std::string productId;
        std::string product;
        std::string productClass;
        std::string additionalInfo;
    };

    struct Library
    {
        static std::vector<CpuInfo> GetAllCPUs();

        static enum IDCPU GetCPU() noexcept;
        static enum IDFPU GetFPU() noexcept;
        static enum IDMMU GetMMU() noexcept;
        static enum IDPPC GetPowerPC() noexcept;

        static std::vector<Expansion> GetExpansions(const enum ClassID filterByClassId = ClassID::NONE) noexcept;

        /// @brief identify:IdHardware()
        static std::string libIdHardware(const enum IDHW idhw) noexcept;

        /// @brief identify:IdHardwareNum()
        static unsigned long libIdHardwareNum(const enum IDHW idhw) noexcept;
    };
}
