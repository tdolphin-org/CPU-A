//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "Components/Windows/GfxChipSpecWindow.hpp"
#include "Core/Singleton.hpp"

#include <vector>

/// @brief holds windows (components)
class WindowManagerCore
{
    friend class td::Singleton<WindowManagerCore>;

    Components::GfxChipSpecWindow mGfxChipSpecWindow;

    std::vector<MUI::Window> mAllWindows;

    WindowManagerCore();
    ~WindowManagerCore();

  public:
    const std::vector<MUI::Window> &getAllWindows() const;

    Components::GfxChipSpecWindow &getGfxChipSpecWindow()
    {
        return mGfxChipSpecWindow;
    }
};

/// @brief main Window Manager (singleton) object
typedef class td::Singleton<WindowManagerCore> WindowManager;
