//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "P96Boards.hpp"
#include "AppContext.hpp"

#include "AOS/Picasso96/Library.hpp"
#include "DataInfo/GfxBoardSpec.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Gauge.hpp"
#include "MUI/Scale.hpp"
#include "MUI/Text.hpp"

#include <numeric>

namespace Components
{
    P96Boards::P96Boards()
      : BoardsBase("Picasso96 Board(s)")
    {
        if (!AppContext::instance().getPicasso96Base().isOpen())
        {
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("Picasso96 not detected")));
            return;
        }

        auto picassoBoards = AOS::Picasso96::Library::GetBoards();
        if (picassoBoards.empty())
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            for (auto &picassoBoard : picassoBoards)
            {
                auto rgbFormats
                    = std::accumulate(picassoBoard.rgbFormats.begin(), picassoBoard.rgbFormats.end(), std::string(""),
                                      [](const std::string &a, const std::string &b) { return a + (a.empty() ? "" : ", ") + b; });

                auto const &gfxBoard = DataInfo::gfxBoardSpecs.at(DataInfo::p96cardName2specIdx.at(picassoBoard.name));
                std::string chipNames = [&]() -> std::string {
                    std::string result;
                    for (auto const chip : gfxBoard.chips)
                        result += (result.empty() ? "" : " or ") + DataInfo::gfxChip2spec.at(chip).modelName;
                    return result;
                }();

                mGfxChipSpecButtons.push_back(new GfxChipSpecButton(gfxBoard.chips));

                mComponent.AddMember(
                    MUI::GroupBuilder()
                        .tagColumns(3)
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Manufacturer").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Premiere").object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(gfxBoard.modelName).object())
                        .tagChild(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::String)
#ifdef MUIA_Text_Shorten
                                      .tagShorten(MUI::Text_Shorten::ElideRight)
#endif
                                      .tagSetMin(false)
                                      .tagContents(gfxBoard.manufacturer)
                                      .tagShortHelp(gfxBoard.manufacturer)
                                      .object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(std::to_string(gfxBoard.premiere)).object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Chip").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Iterface").object())
                        .tagChild(MUI::MakeObject::HVSpace())
                        .tagChild(MUI::GroupBuilder()
                                      .horizontal()
                                      .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(chipNames).object())
                                      .tagChild(*mGfxChipSpecButtons.back())
                                      .object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(gfxBoard.interface).object())
                        .tagChild(MUI::MakeObject::HVSpace())
                        .object());

                mComponent.AddMember(MUI::GaugeBuilder()
                                         .tagHoriz(true)
                                         .tagInfoText(picassoBoard.usedMemory + " used [%ld%%] / " + picassoBoard.memorySize + " @ "
                                                      + picassoBoard.memoryClock)
                                         .tagCurrent(100 - picassoBoard.freeMemoryPercent)
                                         .object());
                mComponent.AddMember(MUI::ScaleBuilder().tagHoriz(true).object());
            }
        }
    }
}
