
//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include <map>
#include <string>

namespace DataInfo
{
    enum class GfxChipID
    {
        Texas_Instruments_TMS34010,
        Inmos_G360,
        Inmos_G364G_10S,
        Inmos_G365,
        Tseng_Labs_ET4000,
        Cirrus_Logic_GD5426,
        Cirrus_Logic_GD5428,
        Cirrus_Logic_GD5434,
        Cirrus_Logic_GD5446,
        NCR_77C32BLT,
        S3_86C764_Trio64,
        S3_86C325_ViRGE,
        _3D_Labs_Permedia_2,
    };

    struct GfxChipSpec
    {
        std::string manufacturer;
        std::string modelName; // chip/model name
        std::string premiere;
        std::string interface; // interface/bus
        std::string technology;
        long coreClock; // Core Clock in MHz
        std::string videoAcceleration;
        std::string memory; // memory spec bit@clock (speed MB/s)
    };

    extern const std::map<GfxChipID, GfxChipSpec> gfxChip2spec;
}
