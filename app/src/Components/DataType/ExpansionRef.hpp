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
    char manufacturer[IDENTIFYBUFLEN];
    char product[IDENTIFYBUFLEN];
    char productClass[IDENTIFYBUFLEN];

    ExpansionRef()
      : configDev(nullptr)
    {
        manufacturer[0] = 0;
        product[0] = 0;
        productClass[0] = 0;
    }

    ExpansionRef(const AOS::Identify::Expansion &expansion)
      : configDev(expansion.configDev)
    {
        strncpy(this->manufacturer, expansion.manufacturer.c_str(), sizeof(this->manufacturer));
        strncpy(this->product, expansion.product.c_str(), sizeof(this->product));
        strncpy(this->productClass, expansion.productClass.c_str(), sizeof(this->productClass));
    }
};
