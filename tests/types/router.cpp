#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <UnitTest++/UnitTest++.h>

#include "../../src/types/inc/number.hpp"
#include "../../src/types/inc/router.hpp"

#include "../config.hpp"

SUITE(TypesRouterTests)
{
    class RouterFixture
    {
    public:
        husky::types::Router router;
    };

    TEST_FIXTURE(RouterFixture, works_with_simple_integer)
    {
        std::stringstream srcLine ("555");
        
		CHECK_EQUAL(husky::types::number::id(),
                    this->router.choose(srcLine)->id());
    }

    TEST_FIXTURE(RouterFixture, works_with_a_double)
    {
        std::stringstream srcLine(", 123.32 sfds");

        srcLine.get();
        srcLine.get();

        CHECK_EQUAL(husky::types::number::id(),
                    this->router.choose(srcLine)->id());
    }
}

/** TODO: checks for exception and for values **/
