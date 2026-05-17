//
//  CPU-A
//
//  (c) 2024-2026 TDolphin
//

#include "ExpansionsList.hpp"

#include "Components/DataType/ExpansionRef.hpp"
#include "Components/MCC/ExpansionsList.hpp"
#include "Core/ToString.hpp"

#include <cstdio>
#include <string>

namespace Components
{
    ExpansionsList::ExpansionsList(const std::vector<AOS::Identify::Expansion> &expansions)
      : mComponent(MCC::ExpansionsListBuilder().tagFormat("BAR,BAR,BAR,").tagTitle(true).tagFrame(MUI::Frame::Group).object())
    {
        for (auto &expansion : expansions)
        {
            const std::string manufacturerId = expansion.manufacturerId != 0 ? ToString::FromHexValue(expansion.manufacturerId, 4) : "";
            const std::string productId = expansion.productId != 0 ? ToString::FromHexValue(expansion.productId, 2) : "";

            ExpansionRef expansionRef { "[" + manufacturerId + "] " + expansion.manufacturerName,
                                        "[" + productId + "] " + expansion.productName, expansion.productClass,
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
            const std::string manufacturerId = expansion.manufacturerId != 0 ? ToString::FromHexValue(expansion.manufacturerId, 4) : "";
            const std::string productId = expansion.productId != 0 ? ToString::FromHexValue(expansion.productId, 4) : "";

            ExpansionRef expansionRef { "[" + manufacturerId + "] " + expansion.manufacturerName,
                                        "[" + productId + "] " + expansion.productName, expansion.productClass, "" };
            mComponent.InsertSingleBottom(&expansionRef);
        }
    }
}
