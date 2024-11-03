//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/Identify/Library.hpp"

#include <cstring>

struct ExpansionRef
{
    struct ConfigDev *configDev;
    char manufacturer[IDENTIFYBUFLEN + 9]; // prefix: "[0xffff] ".size()
    char product[IDENTIFYBUFLEN + 7]; // prefix: "[0xff] ".size()
    char productClass[IDENTIFYBUFLEN];
    char additionalInfo[64];

    ExpansionRef()
      : configDev(nullptr)
    {
        manufacturer[0] = 0;
        product[0] = 0;
        productClass[0] = 0;
        additionalInfo[0] = 0;
    }

    ExpansionRef(const AOS::Identify::Expansion &expansion)
      : configDev(expansion.configDev)
    {
        strncpy(this->manufacturer, (expansion.manufacturerId + expansion.manufacturer).c_str(), sizeof(this->manufacturer));
        strncpy(this->product, (expansion.productId + expansion.product).c_str(), sizeof(this->product));
        strncpy(this->productClass, expansion.productClass.c_str(), sizeof(this->productClass));
        strncpy(this->additionalInfo, expansion.additionalInfo.c_str(), sizeof(this->additionalInfo));
    }
};
