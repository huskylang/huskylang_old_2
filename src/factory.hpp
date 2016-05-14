#ifndef HUSKY_FACTORY_HPP
#define HUSKY_FACTORY_HPP

#include <stack>
#include "base.hpp"

namespace husky {
    
    template <class ObjT>
    class Factory : public Base
    {
    private:
        std::stack<ObjT *> objects;

    public:
        template <typename T, typename ... Types>
        T *create(Types &&... args) {
            T *object = new T(args...);
            this->objects.push((ObjT *) object);
            return object;
        };

        virtual void clean() {
            while (!this->objects.empty()) {
                delete this->objects.top();
                this->objects.pop();
            }
        };
    };

}

#endif
