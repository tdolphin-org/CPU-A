//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

//
// using 'const char *' instead of const std::string &
// for better performance (open and close of application)
// no memory allock/free on start/close
// important for low hardware (AmigaOS 68k)
//

namespace Label
{
    extern const char *CPUTab;
    extern const char *MainboardTab;
    extern const char *MemoryTab;
    extern const char *GraphicsTab;
    extern const char *ExpansionsTab;
    extern const char *BenchTab;
    extern const char *AboutTab;
}
