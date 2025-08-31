//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

//
// using 'const char *' instead of const std::string &
// for better performance (open and close of application)
// no memory allock/free on start/close
// important for low hardware (AmigaOS 68k)
//

namespace Error
{
    extern const char *NoPCILib;
    extern const char *NoPCIDb;
    extern const char *BadPCIDb;
    extern const char *Missing45;
    extern const char *UnknownError;
}
