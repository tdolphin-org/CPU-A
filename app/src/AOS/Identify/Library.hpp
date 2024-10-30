//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "ValueType/IDCPU.hpp"
#include "ValueType/IDFPU.hpp"
#include "ValueType/IDHW.hpp"
#include "ValueType/IDMMU.hpp"
#include "ValueType/IDPPC.hpp"

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
        std::string model;
        std::string revision;
        std::string clock;
    };

    struct Library
    {
        static std::vector<CpuInfo> GetAllCPUs();

        static IDCPU GetCPU() noexcept;
        static IDFPU GetFPU() noexcept;
        static IDMMU GetMMU() noexcept;
        static IDPPC GetPowerPC() noexcept;

        /// @brief identify:IdHardware()
        static std::string libIdHardware(const enum IDHW idhw) noexcept;

        /// @brief identify:IdHardwareNum()
        static unsigned long libIdHardwareNum(const enum IDHW idhw) noexcept;
    };
}
