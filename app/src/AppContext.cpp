//
//  CPU-A
//
//  (c) 2024 TDolphin
//

#include "AppContext.hpp"

#include "App.hpp"

#ifdef TRACE
#include <iostream>
#endif

AppContextCore::AppContextCore()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

AppContextCore::~AppContextCore()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

OpenURLBaseScope &AppContextCore::getOpenURLBase() const
{
    return App::instance().openUrlBase;
}
