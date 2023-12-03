#include "../util/acutest.h"
#include <stdexcept>

void test_case1() {
    TEST_ASSERT(1 == 1);
    TEST_ASSERT(1 != 0);
}

TEST_LIST = {
    {"test_case1", test_case1},
    {nullptr, nullptr}
};
