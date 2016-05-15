#include <iostream>
#include <sstream>

#include "../base.hpp"
#include "../factory.hpp"

#include "inc/router.hpp"
#include "inc/number.hpp"
#include "inc/abstract_type.hpp"

using namespace husky::types;

Router::Router()
{ /* just list here all types */
    this->add<Number>();
}

AbstractType *Router::choose(char ch)
{
    for (auto const &route : routes) {
        if (route.first(ch)) {
            return route.second->clone();
        }
    }

    /* Type not found */

    throw TypeChooseError();
}
