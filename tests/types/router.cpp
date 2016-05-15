#include <iostream>
#include <string>
#include <sstream>
#include <UnitTest++/UnitTest++.h>

#include "../../src/types/inc/number.hpp"
#include "../../src/types/inc/router.hpp"

#include "../config.hpp"
#include "../abstract_fixture.hpp"

SUITE(TypesRouterTests)
{
    class RouterFixture : public husky::tests::AbstractFixture
    {
    public:
        husky::types::Router router;
        husky::types::AbstractType* type;
    };

    TEST_FIXTURE(RouterFixture, works_with_simple_integer)
    {
        std::stringstream srcLine ("555");

        this->type = this->router.choose(srcLine.get()); 

        srcLine.unget();
        
		CHECK_EQUAL(husky::types::number::id,
                    this->type->id());

        CHECK_EQUAL(555, this->type->parse(srcLine)->toDouble());
    }

    TEST_FIXTURE(RouterFixture, works_with_a_double)
    {
        std::stringstream srcLine(", 123.32 sfds");

        srcLine.get();
        srcLine.get();

        this->type = this->router.choose(srcLine.get());

        srcLine.unget();

        CHECK_EQUAL(husky::types::number::id,
                    this->type->id());

        CHECK_EQUAL(123.32, this->type->parse(srcLine)->toDouble());
    }

    TEST_FIXTURE(RouterFixture, throws_choose_error_exception_when_unknown_type)
    {
        std::stringstream srcLine("__*fklsajdf");

        srcLine.get();
        srcLine.get();

        CHECK_THROW(this->router.choose(srcLine.get()),
                    husky::types::TypeChooseError);
    }
}
