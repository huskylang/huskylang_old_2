#include <iostream>
#include <fstream>
#include <UnitTest++/UnitTest++.h>

#include "../src/base.hpp"
#include "../src/factory.hpp"

#include "config.hpp"
#include "factory.hpp"

namespace husky {
    Factory<Base> fact;

    namespace tests {
        Factory<Base> fact;
    }
}

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

    husky::fact.clean();
    husky::tests::fact.clean();

    return retval;
}
