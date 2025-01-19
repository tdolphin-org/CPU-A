//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "GfxChipSpec.hpp"

// data info resources:
// https://www.vgamuseum.info

namespace DataInfo
{
    const std::map<GfxChipID, GfxChipSpec> gfxChip2spec {
        { GfxChipID::Texas_Instruments_TMS34010, { "Texas Instruments", "TMS34010", "1986", "??", "??", 40, "--", "16/32bit" } },
        { GfxChipID::Inmos_G360, { "Inmos", "IMS G360", "~1991", "??", "??", 0, "--", "??" } },
        { GfxChipID::Inmos_G364G_10S, { "Inmos", "IMS G364G-10S", "~1991", "??", "??", 0, "--", "64bit" } },
        { GfxChipID::Inmos_G365, { "Inmos", "IMS G365", "~1991", "??", "??", 0, "--", "64bit" } },
        { GfxChipID::Tseng_Labs_ET4000, { "Tseng Labs", "Tseng ET4000AX", "1989", "ISA 16bit", "1um", 65, "--", "32bit @ 40 MHz" } },
        { GfxChipID::Cirrus_Logic_GD5426, { "Cirrus Logic", "CL-GD5426", "1993", "ISA 16bit, VL-Bus", "??", 80, "--", "32bit @ 50 MHz" } },
        { GfxChipID::Cirrus_Logic_GD5428, { "Cirrus Logic", "CL-GD5428", "1993", "ISA 16bit, VL-Bus", "??", 80, "--", "32bit @ 50 MHz" } },
        { GfxChipID::Cirrus_Logic_GD5434,
          { "Cirrus Logic", "CL-GD5434", "1994", "ISA 16bit, VL-Bus, PCI", "??", 135, "--", "64bit @ 50 MHz" } },
        { GfxChipID::Cirrus_Logic_GD5446,
          { "Cirrus Logic", "CL-GD5446", "1996", "PCI", "??", 135, "MPEG-1 (VCD)", "64bit @ 80 MHz (320 MB/s)" } },
        { GfxChipID::S3_86C764_Trio64, { "S3 Graphics", "S3 Trio64 (86C764)", "1994", "VL-Bus, PCI", "??", 0, "--", "64bit @ 57 MHz" } },
        { GfxChipID::S3_86C325_ViRGE,
          { "S3 Graphics", "S3 ViRGE (86C325)", "13 November 1995", "PCI", "500nm", 72, "MPEG-1 (VCD)", "64bit @ 55 MHz" } },
        { GfxChipID::NCR_77C32BLT, { "NCR Corporation", "NCR 77C32BLT", "1993", "--", "--", 0, "--", "??" } },
        { GfxChipID::_3D_Labs_Permedia_2,
          { "3Dlabs", "3Dlabs Permedia 2", "21 May 1997", "PCI, AGP 1x", "350nm", 83, "MPEG-2 (DVD)", "64bit @ 83 MHz" } },
    };
}
