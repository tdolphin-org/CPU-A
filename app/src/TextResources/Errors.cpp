//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "Errors.hpp"

namespace Error
{
    const char *NoPciLib = "No openpci.library or PCI bridge found";
    const char *NoPciDb = "No PCI database file found";
    const char *BadPciDb = "Bad PCI database file";
    const char *Missing45 = "identify.library version < 45";
    const char *UnknownError = "Unknown error";
}
