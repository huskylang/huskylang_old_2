#ifndef TYPES_NUMBER_HPP
#define TYPES_NUMBER_HPP

#include <sstream>

#include "abstract_type.hpp"

namespace husky {
    namespace types {

        class Number : public AbstractType
        {
        protected:
            double value;

        public:
            Number(std::stringstream &srcLine);
            double toDouble();

            /** TODO toString **/
        };

    }
}

#endif
