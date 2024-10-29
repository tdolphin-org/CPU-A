//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "ValueType/IDHW.hpp"

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
        std::string name;
        std::string revision;
        std::string clock;
    };

    struct Library
    {
        static std::vector<CpuInfo> GetAllCPUs();

        /// @brief identify:IdHardware()
        static std::string libIdHardware(const enum IDHW idhw) noexcept;

        /// @brief identify:IdHardwareNum()
        static unsigned long libIdHardwareNum(const enum IDHW idhw) noexcept;
    };
}
