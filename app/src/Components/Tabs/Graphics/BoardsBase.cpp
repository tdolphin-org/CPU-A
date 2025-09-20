//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "BoardsBase.hpp"

namespace Components
{
    BoardsBase::BoardsBase(const std::string &frameTitle)
      : mComponent(MUI::GroupBuilder()
                       .tagFrame(MUI::Frame::Group)
                       .tagBackground(MUI::ImageOrBackground::WindowBack)
                       .tagFrameTitle(frameTitle)
                       .vertical()
                       .object())
    {
    }
}