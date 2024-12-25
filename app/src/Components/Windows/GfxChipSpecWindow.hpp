//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "Components/Core/Root.hpp"

#include "DataInfo/GfxChipSpec.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class GfxChipSpecWindow : public Root<MUI::Window>
    {
        MUI::Text mManufacturer;
        MUI::Text mModelName;
        MUI::Text mPremiere;
        MUI::Text mInterface;
        MUI::Text mTechnology;
        MUI::Text mCoreClock;
        MUI::Text mVideoAcceleration;
        MUI::Text mMemory;
        MUI::Group mChipSpecGroup;

        MUI::Window mComponent;

      public:
        GfxChipSpecWindow();

        void Open(const std::vector<DataInfo::GfxChipID> &chips);
        void Close();

      protected:
        MUI::Window &muiRoot() const
        {
            return const_cast<MUI::Window &>(mComponent);
        }
    };
}
