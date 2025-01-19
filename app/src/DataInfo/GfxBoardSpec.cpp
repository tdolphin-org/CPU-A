//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "GfxBoardSpec.hpp"

// data info resources:
// https://amiga.resource.cx
// https://bigbookofamigahardware.com

namespace DataInfo
{
    const std::map<AOS::Cybergraphics::BoardID, GfxBoardSpec> gfxBoard2spec {
        { AOS::Cybergraphics::BoardID::CyberVision64,
          { "CyberVision 64", "Phase 5 Digital Products, Germany", { GfxChipID::S3_86C764_Trio64 }, "2/4 MB RAM", 1995, "Zorro III" } },
        { AOS::Cybergraphics::BoardID::Piccolo,
          { "Piccolo", "Ingenieurburo Helfrich, Germany", { GfxChipID::Cirrus_Logic_GD5426 }, "1/2 MB RAM", 1993, "Zorro II/III" } },
        { AOS::Cybergraphics::BoardID::PicassoII,
          { "Picasso II",
            "Village Tronic, Germany",
            { GfxChipID::Cirrus_Logic_GD5426, GfxChipID::Cirrus_Logic_GD5428 },
            "1/2 MB RAM",
            1993,
            "Zorro II" } },
        { AOS::Cybergraphics::BoardID::Spectrum,
          { "EGS 28/24 Spectrum",
            "Great Valley Products, USA",
            { GfxChipID::Cirrus_Logic_GD5426, GfxChipID::Cirrus_Logic_GD5428 },
            "1/2 MB RAM",
            1993,
            "Zorro II/III" } },
        { AOS::Cybergraphics::BoardID::Domino,
          { "Domino",
            "X-Pert Computer Services / Village Tronic, Germany",
            { GfxChipID::Tseng_Labs_ET4000 },
            "1 MB RAM",
            1992,
            "Zorro II" } },
        { AOS::Cybergraphics::BoardID::RetinaZ3,
          { "Retina BLT Z3", "MacroSystem, Germany", { GfxChipID::NCR_77C32BLT }, "4 MB RAM", 1994, "Zorro III" } },
        { AOS::Cybergraphics::BoardID::DraCoAltais,
          { "DraCoAltais", "MacroSystem, Germany", { GfxChipID::NCR_77C32BLT }, "4 MB RAM", 1994, "Zorro III" } },
        { AOS::Cybergraphics::BoardID::PiccoSD64,
          { "Picco SD64", "Ingenieurburo Helfrich, Germany", { GfxChipID::Cirrus_Logic_GD5434 }, "2/4 MB RAM", 1995, "Zorro II/III" } },
        { AOS::Cybergraphics::BoardID::A2410,
          { "A2410", "Commodore, USA", { GfxChipID::Texas_Instruments_TMS34010 }, "2 MB RAM", 1991, "Zorro II" } },
        { AOS::Cybergraphics::BoardID::CyberVision3D,
          { "CyberVision 64/3D", "Phase 5 Digital Products, Germany", { GfxChipID::S3_86C325_ViRGE }, "4 MB RAM", 1996, "Zorro II/III" } },
        { AOS::Cybergraphics::BoardID::Inferno,
          { "Inferno", "DKB, USA", { GfxChipID::Cirrus_Logic_GD5446 }, "4 MB RAM", 1997, "local PCI expansion bus" } },
        { AOS::Cybergraphics::BoardID::PicassoIV,
          { "Picasso IV", "Village Tronic, Germany", { GfxChipID::Cirrus_Logic_GD5446 }, "4 MB RAM", 1996, "Zorro II/III" } },
        { AOS::Cybergraphics::BoardID::Pixel64,
          { "Pixel 64", "Ateo Concepts, France", { GfxChipID::Cirrus_Logic_GD5434 }, "2 MB RAM", 1997, "AteoBus" } },
        { AOS::Cybergraphics::BoardID::RainbowIII,
          { "Rainbow III",
            "Ingenieurburo Helfrich, Germany",
            { GfxChipID::Inmos_G360, GfxChipID::Inmos_G364G_10S, GfxChipID::Inmos_G365 },
            "4 MB RAM",
            1994,
            "Zorro III" } },
        { AOS::Cybergraphics::BoardID::CyberVisonPPC,
          { "CyberVison PPC",
            "Phase 5 Digital Products, Germany",
            { GfxChipID::_3D_Labs_Permedia_2 },
            "8 MB RAM",
            1998,
            "local PCI expansion bus" } },
        { AOS::Cybergraphics::BoardID::BlizzardVisionPPC,
          { "BlizzardVision PPC",
            "Phase 5 Digital Products, Germany",
            { GfxChipID::_3D_Labs_Permedia_2 },
            "8 MB RAM",
            1998,
            "local PCI expansion bus" } },
    };
}