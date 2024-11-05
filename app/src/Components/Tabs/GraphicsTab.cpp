//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "GraphicsTab.hpp"

#include "AOS/Identify/Library.hpp"
#include "AOS/Picasso96/Library.hpp"
#include "AppContext.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    GraphicsTab::GraphicsTab()
      : mGfxSystemText(ValueText("Graphic OS"))
      , mGraphicsCards(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Graphics Card(s)").tagColumns(2).object())
      , mPicasso96Boards(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Picasso96 Board(s)").tagColumns(3).object())
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
                       .tagChild(mPicasso96Boards)
                       .object())
    {
        mGfxSystemText.setContents(AOS::Identify::Library::libIdHardware(AOS::Identify::IDHW::GFXSYS));

        auto graphicsCards = AOS::Identify::Library::GetExpansions(AOS::Identify::ClassID::GFX);
        if (graphicsCards.empty())
            mGraphicsCards.AddTail(LabelText("none"));
        else
        {
            mGraphicsCards.AddTail(MUI::TextBuilder().tagContents("Name").object());
            mGraphicsCards.AddTail(MUI::TextBuilder().tagContents("Manufacturer").object());

            for (auto &graphicsCard : graphicsCards)
            {
                mGraphicsCards.AddTail(MUI::TextBuilder()
                                           .tagFrame(MUI::Frame::String)
                                           .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                           .tagContents(graphicsCard.product)
                                           .object());
                mGraphicsCards.AddTail(MUI::TextBuilder()
                                           .tagFrame(MUI::Frame::String)
                                           .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                           .tagContents(graphicsCard.manufacturer)
                                           .object());
            }
        }

        if (!AppContext::instance().getPicasso96Base().isOpen())
        {
            mPicasso96Boards.AddTail(LabelText("none"));
            return;
        }

        auto picassoBoards = AOS::Picasso96::Library::GetBoards();
        if (picassoBoards.empty())
            mPicasso96Boards.AddTail(LabelText("none"));
        else
        {
            mPicasso96Boards.AddTail(MUI::TextBuilder().tagContents("Name").object());
            mPicasso96Boards.AddTail(MUI::TextBuilder().tagContents("Video Memory Size").object());
            mPicasso96Boards.AddTail(MUI::TextBuilder().tagContents("Video Memory Clock").object());

            for (auto &picassoBoard : picassoBoards)
            {
                mPicasso96Boards.AddTail(MUI::TextBuilder()
                                             .tagFrame(MUI::Frame::String)
                                             .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                             .tagContents(picassoBoard.name)
                                             .object());
                mPicasso96Boards.AddTail(MUI::TextBuilder()
                                             .tagFrame(MUI::Frame::String)
                                             .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                             .tagContents(picassoBoard.memorySize)
                                             .object());
                mPicasso96Boards.AddTail(MUI::TextBuilder()
                                             .tagFrame(MUI::Frame::String)
                                             .tagBackground(MUI::ImageOrBackground::StringActiveBack)
                                             .tagContents(picassoBoard.memoryClock)
                                             .object());
            }
        }
    }
}
