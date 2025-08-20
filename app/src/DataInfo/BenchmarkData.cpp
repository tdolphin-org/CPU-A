//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "BenchmarkData.hpp"

namespace DataInfo
{
    const char *benchmarkReferences[] = { "68030@50MHz (Amiga 500+ 68030TK v2)", nullptr };

    const std::map<ReferenceID, ReferenceBenchmarkData> reference2benchData = {
        { ReferenceID::mc68030at50MHz_Amiga_500plus_68030TK_v2, { benchmarkReferences[0], 88 } },
    };
}
