//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "Core/Singleton.hpp"

class AppContextCore
{
    friend class td::Singleton<AppContextCore>;

    AppContextCore();
    ~AppContextCore();

  public:
    OpenURLBaseScope &getOpenURLBase() const;
};

/// @brief main AppContext (singleton) object
typedef class td::Singleton<AppContextCore> AppContext;
