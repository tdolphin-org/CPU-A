//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "AOS/Identify/IdentifyBaseScope.hpp"
#include "Components/Application.hpp"
#include "Core/Singleton.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

class AppCore
{
    friend class td::Singleton<AppCore>;

    // open libraries, close on destructor
    MuiMasterBaseScope muiBaseScope;
    IdentifyBaseScope identifyBaseScope;

    Components::Application mApplication;

    AppCore();

  public:
    void Run();
};

/// @brief main Application (singleton) object
typedef class td::Singleton<AppCore> App;
