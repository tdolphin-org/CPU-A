//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include <exec/libraries.h>

class IdentifyBaseScope
{
  public:
    /// @brief constructor, opens library, opening can be optional (so means try to open)
    /// @param optional true if open is optional, than get will return nullptr
    IdentifyBaseScope(const bool optional = false);
    ~IdentifyBaseScope();

    bool isOpen() const;
    Library *library() const;
};
