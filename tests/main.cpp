#include <iostream>
#include <fstream>
#include <UnitTest++/UnitTest++.h>

#include "../src/base.hpp"
#include "config.hpp"
#include "factory.hpp"

husky::tests::Factory<husky::Base> fact;

TEST(JustChecksForUnitTestToWork)
{
   CHECK_EQUAL(1, 1);
}

TEST(FileSystemAccess)
{
    try {
        std::string value;

        std::ofstream file_out (husky::tests::Config::tmpfile());
        file_out << "foo bar baz\n";

        file_out.close();

        std::ifstream file_in (husky::tests::Config::tmpfile());
        std::getline(file_in, value);

        file_in.close();

        CHECK_EQUAL("foo bar baz", value);
    } catch (std::exception e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main(int, const char *[])
{
    int retval = UnitTest::RunAllTests();

    fact.clean();

    return retval;
}
