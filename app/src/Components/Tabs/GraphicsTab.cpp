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
      , mGraphicsCards(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Graphics Card(s)").tagColumns(2).object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Graphic System")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mGfxSystemText)
                                     .object())
                       .tagChild(mGraphicsCards)
                       .object())
    {
        mGfxSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::GFXSYS));

        auto graphicsCards = AOS::Identify::Library::GetExpansions(AOS::Identify::ClassID::GFX);
        if (graphicsCards.empty())
            mGraphicsCards.AddTail(LabelText("none"));
        else
        {
            for (auto &graphicsCard : graphicsCards)
            {
                mGraphicsCards.AddTail(MUI::TextBuilder()
                                           .tagFrame(MUI::Frame::String)
                                           .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                           .tagShortHelp("Name")
                                           .tagContents(graphicsCard.product)
                                           .object());
                mGraphicsCards.AddTail(MUI::TextBuilder()
                                           .tagFrame(MUI::Frame::String)
                                           .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                           .tagShortHelp("Manufacturer")
                                           .tagContents(graphicsCard.manufacturer)
                                           .object());
            }
        }
    }
}
