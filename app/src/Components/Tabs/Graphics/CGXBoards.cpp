//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "CGXBoards.hpp"
#include "AppContext.hpp"

#include "AOS/Cybergraphics/Library.hpp"
#include "DataInfo/GfxBoardSpec.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    CGXBoards::CGXBoards()
      : BoardsBase("Cybergraphics Board(s)")
    {
        if (!AppContext::instance().getCybergraphicsBase().isOpen())
        {
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("CyberGraphX not detected")));
            return;
        }

        auto cgxBoards = AOS::Cybergraphics::Library::GetBoards();
        if (cgxBoards.empty())
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            for (auto cgxBoardID : cgxBoards)
            {
                auto const &gfxBoard = DataInfo::gfxBoardSpecs.at(DataInfo::cgxBoardId2specIdx.at(cgxBoardID));
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
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Video Memory Size").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Iterface").object())
                        .tagChild(MUI::GroupBuilder()
                                      .horizontal()
                                      .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(chipNames).object())
                                      .tagChild(*mGfxChipSpecButtons.back())
                                      .object())
                        .tagChild(MUI::TextBuilder()
                                      .tagBackground(MUI::ImageOrBackground::Fill)
                                      .tagFrame(MUI::Frame::String)
                                      .tagContents(gfxBoard.memorySize)
                                      .object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(gfxBoard.interface).object())
                        .object());
            }
        }
    }

    CGXBoards::~CGXBoards()
    {
        for (const auto *pButton : mGfxChipSpecButtons)
            delete pButton;
    }
}
