//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/Cybergraphics//ValueTypes/BoardID.hpp"

#include <map>
#include <string>

namespace DataInfo
{
    struct GfxBoardSpec
    {
        std::string modelName;
        std::string manufacturer;
        std::string chip;
        std::string memorySize;
        int premiere; // year
        std::string interface;
    };

    extern const std::map<AOS::Cybergraphics::BoardID, GfxBoardSpec> gfxBoard2spec;
}
