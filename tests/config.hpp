#ifndef TESTS_CONFIG_HPP
#define TESTS_CONFIG_HPP

#include <string>
#include "../src/base.hpp"

namespace husky {
    namespace tests {
        class Config : public husky::Base
        {
        public:
            static std::string tmpfile() { return "/tmp/husky_programming_language_test_tmpfile"; };
        };
    }
}

#endif
