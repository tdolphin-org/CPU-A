//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"

namespace Components
{
    class AbstractRoot
    {
      public:
        virtual Object *muiObject() const = 0;

        // requesters
        void MuiAlert(const std::string &message) const;
        void MuiWarning(const std::string &message) const;
        void MuiInfo(const std::string &message, const std::string &gadgets) const;
        long MuiRequest(const std::string &title, const std::string &message, const std::string &gadgets) const;
    };

    template <typename T> class Root : public AbstractRoot
    {
      public:
        Object *muiObject() const
        {
            return muiRoot().muiObject();
        }

        operator T &() const
        {
            return (T &)muiRoot();
        }

        virtual T &muiRoot() const = 0;
    };
}
