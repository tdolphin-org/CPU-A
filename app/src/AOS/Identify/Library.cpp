//
//  Git Desktop
//
//  (c) 2022-2024 TDolphin
//

#include "Library.hpp"

#include <proto/identify.h>
#include <libraries/identify.h>

namespace AOS::Identify
{
    std::string Library::cpuName()
    {
        auto result = IdHardware(IDHW_CPU, nullptr);
        return result;
    }
}
