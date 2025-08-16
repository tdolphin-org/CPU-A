//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "WindowManager.hpp"

#ifdef TRACE_MANAGERS
#include "amiga_std_light/iostream.hpp"
#endif

WindowManagerCore::WindowManagerCore()
  : mAllWindows({
        mGfxChipSpecWindow,
    })
{
#ifdef TRACE_MANAGERS
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

WindowManagerCore::~WindowManagerCore()
{
#ifdef TRACE_MANAGERS
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

const std::vector<MUI::Window> &WindowManagerCore::getAllWindows() const
{
#ifdef TRACE_MANAGERS
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    return mAllWindows;
}
