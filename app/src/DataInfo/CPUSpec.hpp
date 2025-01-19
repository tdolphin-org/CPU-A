//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "AOS/Identify/ValueTypes/IDCPU.hpp"
#include "AOS/Identify/ValueTypes/IDPPC.hpp"

#include <map>
#include <string>

namespace DataInfo
{
    enum class FPGAID
    {
        ACA68080
    };

    struct CPUSpec
    {
        std::string vendor;
        std::string modelName;
        std::string coreVoltage;
        std::string technology;
        std::string premiere;
        std::string tdp;
        int totalCores;
        int totalThreads;
        long l1InstructionCache;
        long l1DataCache;
        long l2Cache;
        long l3Cache;
    };

    extern const std::map<AOS::Identify::IDCPU, CPUSpec> cpuMC68k2spec;
    extern const std::map<AOS::Identify::IDPPC, CPUSpec> cpuPPC2spec;
    extern const std::map<FPGAID, CPUSpec> fpga2spec;
}