#ifndef ABSTRACT_FIXTURE_TESTS_HUSKY_HPP
#define ABSTRACT_FIXTURE_TESTS_HUSKY_HPP

namespace husky {
    namespace tests {

        class AbstractFixture
        {
        public:
            template <typename Func>
            auto repeat(Func fun, int times) {
                auto val = fun();
                for (times--; times > 0; times--) val = fun();
                return val;
            };
        };
        
    }
}

#endif
