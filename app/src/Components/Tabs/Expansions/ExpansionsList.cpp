//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "ExpansionsList.hpp"

#include "Components/DataType/ExpansionRef.hpp"
#include "Components/MCC/ExpansionsList.hpp"

#include <iomanip>
#include <sstream>

namespace Components
{
    ExpansionsList::ExpansionsList(const std::vector<AOS::Identify::Expansion> &expansions)
      : mComponent(MCC::ExpansionsListBuilder().tagFormat("BAR,BAR,BAR,").tagTitle(true).tagFrame(MUI::Frame::Group).object())
    {
        for (auto &expansion : expansions)
        {
            std::stringstream manufacturerIdStream, productIdStream;
            if (expansion.manufacturerId != 0)
                manufacturerIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << expansion.manufacturerId;
            if (expansion.productId != 0)
                productIdStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int)expansion.productId;

            ExpansionRef expansionRef { "[" + manufacturerIdStream.str() + "] " + expansion.manufacturerName,
                                        "[" + productIdStream.str() + "] " + expansion.productName, expansion.productClass,
                                        !expansion.additionalInfo.empty() ? expansion.additionalInfo.at(0) : "" };
            mComponent.InsertSingleBottom(&expansionRef);
            for (std::size_t i = 1; i < expansion.additionalInfo.size(); i++)
            {
                ExpansionRef expansionRef { "", "", "", expansion.additionalInfo.at(i) };
                mComponent.InsertSingleBottom(&expansionRef);
            }
        }
    }

    ExpansionsList::ExpansionsList(const std::vector<AOS::Identify::PCIExpansion> &pciExpansions)
      : mComponent(MCC::ExpansionsListBuilder().tagFormat("BAR BAR BAR").tagTitle(true).tagFrame(MUI::Frame::Group).object())
    {
        for (auto &expansion : pciExpansions)
        {
            std::stringstream manufacturerIdStream, productIdStream;
            if (expansion.manufacturerId != 0)
                manufacturerIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << expansion.manufacturerId;
            if (expansion.productId != 0)
                productIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << (int)expansion.productId;

            ExpansionRef expansionRef { "[" + manufacturerIdStream.str() + "] " + expansion.manufacturerName,
                                        "[" + productIdStream.str() + "] " + expansion.productName, expansion.productClass, "" };
            mComponent.InsertSingleBottom(&expansionRef);
        }
    }
}
