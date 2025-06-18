//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "AppContext.hpp"

#include "App.hpp"

#ifdef TRACE
#include <iostream>
#endif

AppContextCore::AppContextCore()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    // normal expansions
    mExpansions = AOS::Identify::Library::GetExpansions();

    // pci expansions
    auto pciExpansions = AOS::Identify::Library::GetPciExpansions();
    mPciExpansionsResultCode = pciExpansions.first;
    mPciExpansions = pciExpansions.second;
}

AppContextCore::~AppContextCore()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

OpenURLBaseScope &AppContextCore::getOpenURLBase() const
{
    return App::instance().openUrlBaseScope;
}

Picasso96BaseScope &AppContextCore::getPicasso96Base() const
{
    return App::instance().picasso96BaseScope;
}

CybergraphicsBaseScope &AppContextCore::getCybergraphicsBase() const
{
    return App::instance().cybergraphicsBaseScope;
}

bool AppContextCore::hasExpansion(const unsigned short manufacturerId, const unsigned char productId) const
{
    for (const auto &expansion : mExpansions)
        if (expansion.manufacturerId == manufacturerId && expansion.productId == productId)
            return true;

    return false;
}

bool AppContextCore::hasOneOfExpansions(const unsigned short manufacturerId, const std::set<unsigned char> &productIds) const
{
    for (const auto &expansion : mExpansions)
        if (expansion.manufacturerId == manufacturerId && productIds.find(expansion.productId) != productIds.end())
            return true;

    return false;
}
