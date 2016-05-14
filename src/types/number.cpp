#include <string>
#include <sstream>

#include "../config.hpp"

#include "inc/number.hpp"

using namespace husky::types;

std::string number::id()
{
    return "number";
}

Number::Number(std::stringstream &srcLine)
{
    srcLine >> this->value;
}

double Number::toDouble()
{
    return this->value;
}
