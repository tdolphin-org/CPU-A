//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "CgxBoards.hpp"
#include "AppContext.hpp"

#include "AOS/Cybergraphics/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

#include <iostream>

namespace Components
{
    CgxBoards::CgxBoards()
      : mComponent(MUI::GroupBuilder()
                       .tagFrame(MUI::Frame::Group)
                       .tagBackground(MUI::ImageOrBackground::WindowBack)
                       .tagFrameTitle("Cybergraphics Board(s)")
                       .vertical()
                       .object())
    {
        if (!AppContext::instance().getCybergraphicsBase().isOpen())
        {
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("Cybergraphics not detected")));
            return;
        }

        auto cgxBoards = AOS::Cybergraphics::Library::GetBoards();
        if (cgxBoards.empty())
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            for (auto &cgxBoard : cgxBoards)
            {
                mComponent.AddMember(
                    MUI::GroupBuilder()
                        .tagColumns(3)
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Manufacturer").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Premiere").object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(cgxBoard.name).object())
                        .tagChild(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::String)
#ifdef MUIA_Text_Shorten
                                      .tagShorten(MUI::Text_Shorten::ElideRight)
#endif
                                      .tagSetMin(false)
                                      .tagContents(cgxBoard.manufacturer)
                                      .tagShortHelp(cgxBoard.manufacturer)
                                      .object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(std::to_string(cgxBoard.premiere)).object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Chip").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Video Memory Size").object())
                        .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Iterface").object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(cgxBoard.chip).object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(cgxBoard.memorySize).object())
                        .tagChild(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(cgxBoard.interface).object())
                        .object());
            }
        }
    }
}
