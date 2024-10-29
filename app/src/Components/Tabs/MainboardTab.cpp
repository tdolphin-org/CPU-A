//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "MainboardTab.hpp"

#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    MainboardTab::MainboardTab()
      : mComponent(MUI::GroupBuilder().vertical().tagChild(MUI::MakeObject::FreeLabel("Mainboard")).object())
    {
    }
}