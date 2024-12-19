//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "GraphicsTab.hpp"

#include "AOS/Graphics/Library.hpp"
#include "AOS/Identify/Library.hpp"
#include "Graphics/CGXBoards.hpp"
#include "Graphics/P96Boards.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Core/NullObject.hpp"

namespace Components
{
    GraphicsTab::GraphicsTab()
      : mGfxSystemText(ValueText("Graphic OS"))
      , mGraphicsCards(MUI::GroupBuilder()
                           .tagFrame(MUI::Frame::Group)
                           .tagBackground(MUI::ImageOrBackground::WindowBack)
                           .tagFrameTitle("Graphics Card(s)")
                           .tagColumns(2)
                           .object())
      , mMountedMonitors(MUI::GroupBuilder()
                             .tagFrame(MUI::Frame::Group)
                             .tagBackground(MUI::ImageOrBackground::WindowBack)
                             .tagFrameTitle("Mounted Devs Monitor(s)")
                             .object())
      , mGfxBoards([]() -> MUI::Root {
          switch (AOS::Identify::Library::GetGraphicOS())
          {
              case AOS::Identify::IDGOS::PICASSO96:
                  return P96Boards();
              case AOS::Identify::IDGOS::CGX4:
                  return CGXBoards();
              default:
                  return MUI::NullObject();
          }
      }())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("Graphic System")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mGfxSystemText)
                                     .object())
                       .tagChild(mMountedMonitors)
                       .tagChild(mGraphicsCards)
                       .tagChild(mGfxBoards)
                       .object())
    {
        mGfxSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::GFXSYS));

        auto graphicsCards = AOS::Identify::Library::GetExpansions(AOS::Identify::ClassID::GFX);
        if (graphicsCards.empty())
            mGraphicsCards.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            mGraphicsCards.AddMember(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name").object());
            mGraphicsCards.AddMember(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Manufacturer").object());

            for (auto &graphicsCard : graphicsCards)
            {
                mGraphicsCards.AddMember(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(graphicsCard.product).object());
                mGraphicsCards.AddMember(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(graphicsCard.manufacturer).object());
            }
        }

        auto mountedMonitors = AOS::Graphics::Library::GetMonitors();
        if (mountedMonitors.empty())
            mMountedMonitors.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            mMountedMonitors.setColumns(mountedMonitors.size() < 4 ? mountedMonitors.size() : 4);
            for (const auto &monitorName : mountedMonitors)
                mMountedMonitors.AddMember(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(monitorName).object());
        }
    }
}
