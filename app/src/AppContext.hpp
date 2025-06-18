//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#pragma once

#include "AOS/Cybergraphics/CybergraphicsBaseScope.hpp"
#include "AOS/Identify/Library.hpp"
#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "AOS/Picasso96/Picasso96BaseScope.hpp"
#include "Core/Singleton.hpp"

#include <set>

class AppContextCore
{
    friend class td::Singleton<AppContextCore>;

    AppContextCore();
    ~AppContextCore();

    std::vector<AOS::Identify::Expansion> mExpansions;
    AOS::Identify::PciExpansionsResultCode mPciExpansionsResultCode;
    std::vector<AOS::Identify::PciExpansion> mPciExpansions;

  public:
    OpenURLBaseScope &getOpenURLBase() const;
    Picasso96BaseScope &getPicasso96Base() const;
    CybergraphicsBaseScope &getCybergraphicsBase() const;

    const std::vector<AOS::Identify::Expansion> &getExpansions() const
    {
        return mExpansions;
    }

    AOS::Identify::PciExpansionsResultCode getPciExpansionsResultCode() const
    {
        return mPciExpansionsResultCode;
    }

    const std::vector<AOS::Identify::PciExpansion> &getPciExpansions() const
    {
        return mPciExpansions;
    }

    bool hasExpansion(const unsigned short manufacturerId, const unsigned char productId) const;
    bool hasOneOfExpansions(const unsigned short manufacturerId, const std::set<unsigned char> &productIds) const;
};

/// @brief main AppContext (singleton) object
typedef class td::Singleton<AppContextCore> AppContext;
