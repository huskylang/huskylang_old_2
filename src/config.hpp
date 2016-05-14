#ifndef HUSKY_CONFIG_HPP
#define HUSKY_CONFIG_HPP

#include <string>

#include "base.hpp"
#include "factory.hpp"

namespace husky {
    class Config : public husky::Base
    {
        //
    };
        
    extern Factory<Base> fact;
}

#endif
