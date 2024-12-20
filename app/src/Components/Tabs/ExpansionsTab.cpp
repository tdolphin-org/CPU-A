//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "ExpansionsTab.hpp"

#include "AppContext.hpp"
#include "AOS/Identify/Library.hpp"
#include "Components/DataType/ExpansionRef.hpp"
#include "MUI/Core/MakeObject.hpp"

#include <iomanip>
#include <sstream>

namespace Components
{
    ExpansionsTab::ExpansionsTab()
      : mExpansionsList(MCC::ExpansionsListBuilder().tagFormat("BAR,BAR,BAR,").tagTitle(true).tagFrame(MUI::Frame::Group).object())
      , mComponent(MUI::GroupBuilder().vertical().tagChild(mExpansionsList).object())
    {
        auto expansions = AppContext::instance().getExpansions();
        for (auto &expansion : expansions)
        {
            std::stringstream manufacturerIdStream, productIdStream;
            if (expansion.manufacturerId != 0)
                manufacturerIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << expansion.manufacturerId;
            if (expansion.productId != 0)
                productIdStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int)expansion.productId;

            ExpansionRef expansionRef { "[" + manufacturerIdStream.str() + "] " + expansion.manufacturer,
                                        "[" + productIdStream.str() + "] " + expansion.product, expansion.productClass,
                                        !expansion.additionalInfo.empty() ? expansion.additionalInfo.at(0) : "" };
            mExpansionsList.InsertSingleBottom(&expansionRef);
            for (std::size_t i = 1; i < expansion.additionalInfo.size(); i++)
            {
                ExpansionRef expansionRef { "", "", "", expansion.additionalInfo.at(i) };
                mExpansionsList.InsertSingleBottom(&expansionRef);
            }
        }
    }
}
