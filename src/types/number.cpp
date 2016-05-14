#include <string>
#include <sstream>

#include "inc/number.hpp"

using namespace husky::types;

Number::Number(std::stringstream &srcLine)
{
    srcLine >> this->value;
}

double Number::toDouble()
{
    return this->value;
}
