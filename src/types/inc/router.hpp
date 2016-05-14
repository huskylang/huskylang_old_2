#ifndef HUSKY_TYPES_ROUTER_HPP
#define HUSKY_TYPES_ROUTER_HPP

#include <map>
#include <sstream>

#include "../../base.hpp"
#include "../../factory.hpp"
#include "../../config.hpp"

#include "abstract_type.hpp"

/** TODO: remove method **/

namespace husky {
    namespace types {

        using husky::fact;
        using check_t = bool (*)(char);
        using maker_t = AbstractType *;

        class Router : public husky::Base
        {
        protected:
            std::map<check_t, maker_t> routes;

        public:
            Router();
            virtual AbstractType *choose(std::stringstream &srcLine);

            template <typename T>
            void add() {
                this->routes[&T::check] = fact.create<T>(std::stringstream(""));
            };
        };

        class TypeChooseError : public std::exception
        {
            const char *what() const throw() {
                return "can't choose a type";
            };
        };

    }
}

#endif
