//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "Errors.hpp"

namespace Error
{
    const char *NoPCILib = "No openpci.library or PCI bridge found";
    const char *NoPCIDb = "No PCI database file found";
    const char *BadPCIDb = "Bad PCI database file";
    const char *Missing45 = "identify.library version < 45";
    const char *UnknownError = "Unknown error";
}
