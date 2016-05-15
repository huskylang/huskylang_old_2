#ifndef HUKSY_ABSTRACT_TYPE_HPP
#define HUKSY_ABSTRACT_TYPE_HPP

#include <sstream>

#include "../../base.hpp"

namespace husky {
    namespace types {

        class AbstractType : public husky::Base
        {
        public:
            virtual AbstractType *clone() = 0;
            virtual AbstractType *parse(std::stringstream&) = 0;
            virtual std::string id() = 0;
            
            virtual double toDouble() { return 0; };
            virtual std::string toString() { return ""; };
        };
        
    }
}

#endif
