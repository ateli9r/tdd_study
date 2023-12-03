#include <stdexcept>
#include "../util/acutest.h"
#include "include/money.h"

void testMultiplication() {
    auto five = Money::dollar(5); // $5
    TEST_ASSERT(Money::dollar(10) == five.times(2)); // $5 x 2 = 10$
    TEST_ASSERT(Money::dollar(15) == five.times(3)); // $5 x 3 = 15$
}

void testEquality() {
    TEST_ASSERT(Money::dollar(5) == Money::dollar(5)); // $5 == $5
    TEST_ASSERT(Money::dollar(5) != Money::dollar(6)); // $5 != $6
    TEST_ASSERT(Money::franc(5) != Money::dollar(5)); // 5CHF != $5
}

void testCurrency() {
    TEST_ASSERT(Money::dollar(1).currency().compare("USD") == 0); // 1$ = USD
    TEST_ASSERT(Money::franc(1).currency().compare("CHF") == 0); // 1CHF = CHF
}

TEST_LIST = {
    {"testMultiplication", testMultiplication},
    {"testEquality", testEquality},
    {"testCurrency", testCurrency},
    {nullptr, nullptr}
};
