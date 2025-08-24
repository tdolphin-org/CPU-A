//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "GfxBoardSpec.hpp"

// data info resources:
// https://amiga.resource.cx
// https://bigbookofamigahardware.com
// https://github.com/henrikstengaard/picasso96-package/tree/master/package/Picasso96Install/Libs/Picasso96

namespace DataInfo
{
    const std::vector<GfxBoardSpec> gfxBoardSpecs {
        { "CyberVision 64", "Phase 5 Digital Products, Germany", { GfxChipID::S3_86C764_Trio64 }, "2/4 MB RAM", 1995, "Zorro III" }, // 0
        { "Piccolo", "Ingenieurburo Helfrich, Germany", { GfxChipID::Cirrus_Logic_GD5426 }, "1/2 MB RAM", 1993, "Zorro II/III" }, // 1
        { "Picasso II", // 2
          "Village Tronic, Germany",
          { GfxChipID::Cirrus_Logic_GD5426, GfxChipID::Cirrus_Logic_GD5428 },
          "1/2 MB RAM",
          1993,
          "Zorro II" },
        { "EGS 28/24 Spectrum", // 3
          "Great Valley Products, USA",
          { GfxChipID::Cirrus_Logic_GD5426, GfxChipID::Cirrus_Logic_GD5428 },
          "1/2 MB RAM",
          1993,
          "Zorro II/III" },
        { "Domino", // 4
          "X-Pert Computer Services / Village Tronic, Germany",
          { GfxChipID::Tseng_Labs_ET4000 },
          "1 MB RAM",
          1992,
          "Zorro II" },
        { "Retina BLT Z3", "MacroSystem, Germany", { GfxChipID::NCR_77C32BLT }, "4 MB RAM", 1994, "Zorro III" }, // 5
        { "DraCoAltais", "MacroSystem, Germany", { GfxChipID::NCR_77C32BLT }, "4 MB RAM", 1994, "Zorro III" }, // 6
        { "Picco SD64", "Ingenieurburo Helfrich, Germany", { GfxChipID::Cirrus_Logic_GD5434 }, "2/4 MB RAM", 1995, "Zorro II/III" }, // 7
        { "A2410", "Commodore, USA", { GfxChipID::Texas_Instruments_TMS34010 }, "2 MB RAM", 1991, "Zorro II" }, // 8
        { "CyberVision 64/3D", "Phase 5 Digital Products, Germany", { GfxChipID::S3_86C325_ViRGE }, "4 MB RAM", 1996, "Zorro II/III" }, // 9
        { "Inferno", "DKB, USA", { GfxChipID::Cirrus_Logic_GD5446 }, "4 MB RAM", 1997, "local PCI expansion bus" }, // 10
        { "Picasso IV", "Village Tronic, Germany", { GfxChipID::Cirrus_Logic_GD5446 }, "4 MB RAM", 1996, "Zorro II/III" }, // 11
        { "Pixel 64", "Ateo Concepts, France", { GfxChipID::Cirrus_Logic_GD5434 }, "2 MB RAM", 1997, "AteoBus" }, // 12
        { "Rainbow III", // 13
          "Ingenieurburo Helfrich, Germany",
          { GfxChipID::Inmos_G360, GfxChipID::Inmos_G364G_10S, GfxChipID::Inmos_G365 },
          "4 MB RAM",
          1994,
          "Zorro III" },
        { "CyberVison PPC", // 14
          "Phase 5 Digital Products, Germany",
          { GfxChipID::_3D_Labs_Permedia_2 },
          "8 MB RAM",
          1998,
          "local PCI expansion bus" },
        { "BlizzardVision PPC", // 15
          "Phase 5 Digital Products, Germany",
          { GfxChipID::_3D_Labs_Permedia_2 },
          "8 MB RAM",
          1998,
          "local PCI expansion bus" },
        { "UAE GFX", "UAE", { GfxChipID::Emulated }, "16 MB RAM", 1995, "--/Zorro II/Zorro III" }, // 16
        { "oMniBus", "ArMax, Germany", { GfxChipID::Tseng_Labs_ET4000AX }, "1 MB RAM", 1993, "Zorro II" }, // 17
        { "Merlin",
          "X-Pert Computer Services / Prodev, Germany",
          { GfxChipID::Tseng_Labs_ET4000_W32 },
          "2/4 MB RAM",
          1993,
          "Zorro II/III" }, // 18
        { "Graffity", "Individual Computers, Germany", { GfxChipID::Emulated }, "4 MB RAM", 1994, "RGB Port" }, // 19
    };

    const std::map<AOS::Cybergraphics::BoardID, size_t> cgxBoardId2specIdx {
        { AOS::Cybergraphics::BoardID::CyberVision64, 0 },  { AOS::Cybergraphics::BoardID::Piccolo, 1 },
        { AOS::Cybergraphics::BoardID::PicassoII, 2 },      { AOS::Cybergraphics::BoardID::Spectrum, 3 },
        { AOS::Cybergraphics::BoardID::Domino, 4 },         { AOS::Cybergraphics::BoardID::RetinaZ3, 5 },
        { AOS::Cybergraphics::BoardID::DraCoAltais, 6 },    { AOS::Cybergraphics::BoardID::PiccoSD64, 7 },
        { AOS::Cybergraphics::BoardID::A2410, 8 },          { AOS::Cybergraphics::BoardID::CyberVision3D, 9 },
        { AOS::Cybergraphics::BoardID::Inferno, 10 },       { AOS::Cybergraphics::BoardID::PicassoIV, 11 },
        { AOS::Cybergraphics::BoardID::Pixel64, 12 },       { AOS::Cybergraphics::BoardID::RainbowIII, 13 },
        { AOS::Cybergraphics::BoardID::CyberVisonPPC, 14 }, { AOS::Cybergraphics::BoardID::BlizzardVisionPPC, 15 },
    };

    const std::map<std::string, size_t> p96cardName2specIdx {
        { "Altais.card", 6 },   { "CVision3D.card", 9 }, { "CyberVision.card", 0 }, { "Domino.card", 4 },   { "Graffity.card", 19 },
        { "Merlin.card", 18 },  { "PicassoII.card", 2 }, { "PicassoIV.card", 11 },  { "Piccolo.card", 1 },  { "PiccoloSD64.card", 7 },
        { "Pixel64.card", 12 }, { "RetinaBLT.card", 5 }, { "Spectrum.card", 3 },    { "oMniBus.card", 17 }, { "uaegfx.card", 16 },
    };
}