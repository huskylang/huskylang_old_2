#ifndef HUSKY_TESTS_FACTORY
#define HUSKY_TESTS_FACTORY

#include "../src/factory.hpp"

namespace husky {
    namespace tests {

        template <class ObjT>
        class Factory : public husky::Factory<ObjT>
        {
            //
        };

    }
}

#endif
