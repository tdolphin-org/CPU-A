//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include <map>
#include <string>

namespace DataInfo
{
    enum class ReferenceID
    {
        mc68030at50MHz_Amiga_500plus_68030TK_v2,
    };

    struct ReferenceBenchmarkData
    {
        std::string fullname; // full name of the reference
        long benchmark01result; // operations per second
    };

    extern const char *benchmarkReferences[]; // for displaying reference names (cycle)

    extern const std::map<ReferenceID, ReferenceBenchmarkData> reference2benchData;
}
