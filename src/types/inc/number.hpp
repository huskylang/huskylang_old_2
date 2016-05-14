#ifndef HUSKY_TYPES_NUMBER_HPP
#define HUSKY_TYPES_NUMBER_HPP

#include <sstream>
#include <ctype.h>

#include "abstract_type.hpp"

namespace husky {
    namespace types {

        namespace number {
            extern std::string id();
        }

        class Number : public AbstractType
        {
        protected:
            double value;

        public:
            Number(std::stringstream &srcLine);
            virtual Number *clone(std::stringstream &srcLine) { return new Number(srcLine); };
            
            virtual double toDouble();
            virtual std::string toString() { return ""; };
            
            static bool check(char ch) { return isdigit(ch); };
            virtual std::string id() { return number::id(); };

            /** TODO toString **/
        };
    }
}

#endif
