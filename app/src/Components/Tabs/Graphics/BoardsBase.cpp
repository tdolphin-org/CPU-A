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