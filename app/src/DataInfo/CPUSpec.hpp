//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/Identify/ValueType/IDCPU.hpp"
#include "AOS/Identify/ValueType/IDPPC.hpp"

#include <map>
#include <string>

namespace DataInfo
{
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
    };

    extern const std::map<AOS::Identify::IDCPU, CPUSpec> cpuMC68k2spec;

    extern const std::map<AOS::Identify::IDPPC, CPUSpec> cpuPPC2spec;
}