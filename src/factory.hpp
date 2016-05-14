#ifndef HUSKY_FACTORY_HPP
#define HUSKY_FACTORY_HPP

#include <vector>
#include "base.hpp"

namespace husky {
    
    template <class ObjT>
    class Factory : public Base
    {
    private:
        std::vector<ObjT *> objects;

    public:
        template <typename T, typename ... Types>
        T *create(Types &&... args) {
            T *object = new T(args...);
            this->objects.push_back((ObjT *) object);
            return object;
        };

        virtual void clean() {
            for (ObjT *object : this->objects) {
                delete object;
            }
        };
    };

}

#endif
