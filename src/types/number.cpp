#include <string>
#include <sstream>

#include "../config.hpp"

#include "inc/number.hpp"

using husky::fact;

using namespace husky::types;

Number *Number::parse(std::stringstream &srcLine)
{
    srcLine >> this->value;
    return this;
}

Number *Number::clone()
{
    return fact.create<Number>();
}

/** Getters **/

double Number::toDouble()
{
    return this->value;
}

/** TODO when lists **/
std::string Number::toString()
{
    return "";
}
