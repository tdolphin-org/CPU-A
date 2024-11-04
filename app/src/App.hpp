//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/Identify/IdentifyBaseScope.hpp"
#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "Components/Application.hpp"
#include "Core/Singleton.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

class AppContextCore;

class AppCore
{
    friend class td::Singleton<AppCore>;
    friend class AppContextCore;

    // open libraries, close on destructor
    MuiMasterBaseScope muiBaseScope;
    IdentifyBaseScope identifyBaseScope;
    OpenURLBaseScope openUrlBase;

    Components::Application mApplication;

    AppCore();

  public:
    void Run();
};

/// @brief main Application (singleton) object
typedef class td::Singleton<AppCore> App;
