#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <UnitTest++/UnitTest++.h>

#include "../../src/types/inc/number.hpp"

#include "../config.hpp"

using husky::tests::fact;

SUITE(TypesNumberTests)
{
    class NumberFixture
    {
    public:
        husky::types::Number *number;

        husky::types::Number *init(std::stringstream &srcLine) {
            return this->number = fact.create<husky::types::Number>(srcLine);
        };
    };

    TEST_FIXTURE(NumberFixture, works_with_simple_integer)
    {
        std::stringstream srcLine ("19283");
		CHECK_EQUAL(19283,
                    this->init(srcLine)->toDouble());
    }

    TEST_FIXTURE(NumberFixture, works_with_characters_before_it)
    {
        std::stringstream srcLine ("jlk53829");

        srcLine.get();
        srcLine.get();
        srcLine.get();

		CHECK_EQUAL(53829,
                    this->init(srcLine)->toDouble());
    }

    TEST_FIXTURE(NumberFixture, works_with_characters_after_it)
    {
        std::string value;
        std::stringstream srcLine ("17823, micaldkj");

		CHECK_EQUAL(17823,
                    this->init(srcLine)->toDouble());

        srcLine >> value;
        CHECK_EQUAL(",", value);

        srcLine >> value;
        CHECK_EQUAL("micaldkj", value);
    }

    TEST_FIXTURE(NumberFixture, works_with_one_digit)
    {
        std::stringstream srcLine ("1");

		CHECK_EQUAL(1,
                    this->init(srcLine)->toDouble());
    }

    TEST_FIXTURE(NumberFixture, works_with_double_values)
    {
        std::string value;
        std::stringstream srcLine ("120.12982,klamiv");

		CHECK_EQUAL(120.12982,
                    this->init(srcLine)->toDouble());

        srcLine >> value;
        CHECK_EQUAL(",klamiv", value);
    }
}
