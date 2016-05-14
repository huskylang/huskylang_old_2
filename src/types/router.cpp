#include <sstream>
#include <map>

#include "../base.hpp"
#include "../factory.hpp"

#include "inc/router.hpp"
#include "inc/number.hpp"
#include "inc/abstract_type.hpp"

using namespace husky::types;

Router::Router()
{
    this->add<Number>();
}

AbstractType *Router::choose(std::stringstream &srcLine)
{
    char ch;
    
    srcLine >> ch;
    srcLine.putback(ch);

    for (auto const &route : routes)
        if (route.first(ch)) return route.second->clone(srcLine);

    throw(new TypeChooseError());
}
