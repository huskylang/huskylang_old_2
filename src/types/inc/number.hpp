#ifndef HUSKY_TYPES_NUMBER_HPP
#define HUSKY_TYPES_NUMBER_HPP

#include <sstream>
#include <ctype.h>

#include "abstract_type.hpp"

namespace husky {
    namespace types {

        namespace number {
            static const std::string id = "number";
        }
        
        class Number : public AbstractType
        {
        private:
            double value;

        public:
            virtual Number *clone();
            virtual Number *parse(std::stringstream &srcLine);
            
            virtual double toDouble();
            virtual std::string toString();
            
            static bool check(char ch) { return isdigit(ch); };
            virtual std::string id() { return number::id; };
        };
        
    }
}

#endif
