//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "AOS/Cybergraphics/ValueTypes/BoardID.hpp"
#include "GfxChipSpec.hpp"

#include <map>
#include <string>
#include <vector>

namespace DataInfo
{
    struct GfxBoardSpec
    {
        std::string modelName;
        std::string manufacturer;
        std::vector<GfxChipID> chips; // possible or
        std::string memorySize;
        int premiere; // year
        std::string interface;
    };

    extern const std::vector<GfxBoardSpec> gfxBoardSpecs;

    extern const std::map<AOS::Cybergraphics::BoardID, size_t> cgxBoardId2specIdx;
    extern const std::map<std::string, size_t> p96cardName2specIdx;
}
