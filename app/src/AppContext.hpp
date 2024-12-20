//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "AOS/Picasso96/Picasso96BaseScope.hpp"
#include "AOS/Cybergraphics/CybergraphicsBaseScope.hpp"
#include "AOS/Identify/Library.hpp"
#include "Core/Singleton.hpp"

class AppContextCore
{
    friend class td::Singleton<AppContextCore>;

    AppContextCore();
    ~AppContextCore();

    std::vector<AOS::Identify::Expansion> mExpansions;

  public:
    OpenURLBaseScope &getOpenURLBase() const;
    Picasso96BaseScope &getPicasso96Base() const;
    CybergraphicsBaseScope &getCybergraphicsBase() const;

    std::vector<AOS::Identify::Expansion> getExpansions() const
    {
        return mExpansions;
    }
};

/// @brief main AppContext (singleton) object
typedef class td::Singleton<AppContextCore> AppContext;
