//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "GraphicsTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    GraphicsTab::GraphicsTab()
      : mGfxSystemText(ValueText("Graphic OS"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Graphic System")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mGfxSystemText)
                                     .object())
                       .object())
    {
        mGfxSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::GFXSYS));
    }
}
