//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include <cstring>
#include <libraries/identify.h>

// expansion reference structure for MUI list
struct ExpansionRef
{
    char manufacturer[IDENTIFYBUFLEN + 9]; // prefix: "[0xffff] ".size()
    char product[IDENTIFYBUFLEN + 7]; // prefix: "[0xff] ".size()
    char productClass[IDENTIFYBUFLEN];
    char additionalInfo[64];

    ExpansionRef()
    {
        manufacturer[0] = 0;
        product[0] = 0;
        productClass[0] = 0;
        additionalInfo[0] = 0;
    }

    ExpansionRef(const std::string &manufacturer, const std::string &product, const std::string &productClass,
                 const std::string &additionalInfo)
    {
        strncpy(this->manufacturer, manufacturer.c_str(), sizeof(this->manufacturer));
        strncpy(this->product, product.c_str(), sizeof(this->product));
        strncpy(this->productClass, productClass.c_str(), sizeof(this->productClass));
        strncpy(this->additionalInfo, additionalInfo.c_str(), sizeof(this->additionalInfo));
    }
};
