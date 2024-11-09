//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "GraphicsTab.hpp"

#include "AOS/Graphics/Library.hpp"
#include "AOS/Identify/Library.hpp"
#include "AOS/Picasso96/Library.hpp"
#include "AppContext.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Gauge.hpp"

#include <numeric>

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
                             .tagColumns(4)
                             .object())
      , mPicasso96Boards(MUI::GroupBuilder()
                             .tagFrame(MUI::Frame::Group)
                             .tagBackground(MUI::ImageOrBackground::WindowBack)
                             .tagFrameTitle("Picasso96 Board(s)")
                             .vertical()
                             .object())
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
                       .tagChild(mPicasso96Boards)
                       .object())
    {
        mGfxSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::GFXSYS));

        auto graphicsCards = AOS::Identify::Library::GetExpansions(AOS::Identify::ClassID::GFX);
        if (graphicsCards.empty())
            mGraphicsCards.AddTail(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            mGraphicsCards.AddTail(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name").object());
            mGraphicsCards.AddTail(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Manufacturer").object());

            for (auto &graphicsCard : graphicsCards)
            {
                mGraphicsCards.AddTail(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(graphicsCard.product).object());
                mGraphicsCards.AddTail(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(graphicsCard.manufacturer).object());
            }
        }

        for (auto &monitorName : AOS::Graphics::Library::GetMonitors())
            mMountedMonitors.AddTail(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(monitorName).object());

        if (!AppContext::instance().getPicasso96Base().isOpen())
        {
            mPicasso96Boards.AddTail(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
            return;
        }

        auto picassoBoards = AOS::Picasso96::Library::GetBoards();
        if (picassoBoards.empty())
            mPicasso96Boards.AddTail(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            for (auto &picassoBoard : picassoBoards)
            {
                auto rgbFormats
                    = std::accumulate(picassoBoard.rgbFormats.begin(), picassoBoard.rgbFormats.end(), std::string(""),
                                      [](const std::string &a, const std::string &b) { return a + (a.empty() ? "" : ", ") + b; });
                mPicasso96Boards.AddTail(
                    MUI::GroupBuilder()
                        .tagColumns(3)
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Chip").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("RGB Formats").object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(picassoBoard.name).object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(picassoBoard.chip).object())
                        .tagChild(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::String)
                                      .tagShorten(MUI::Text_Shorten::ElideRight)
                                      .tagSetMin(false)
                                      .tagContents(rgbFormats)
                                      .tagShortHelp(rgbFormats)
                                      .object())
                        .object());

                mPicasso96Boards.AddTail(MUI::GaugeBuilder()
                                             .tagHoriz(true)
                                             .tagInfoText(picassoBoard.memorySize + " [%ld %% used] @ " + picassoBoard.memoryClock)
                                             .tagCurrent(100 - picassoBoard.freeMemoryPercent)
                                             .object());
            }
        }
    }
}
