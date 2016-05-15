#ifndef HUSKY_TYPES_ROUTER_HPP
#define HUSKY_TYPES_ROUTER_HPP

#include <map>
#include <exception>

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
            virtual AbstractType *choose(char ch);

            template <typename T>
            void add() {
                this->routes[&T::check] = fact.create<T>();
            };
        };

        class TypeChooseError : public std::exception
        {
        public:
            virtual const char *what() const noexcept {
                return "can't choose a type";
            };
        };

    }
}

#endif
