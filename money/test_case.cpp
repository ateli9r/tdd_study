#include "../util/acutest.h"
#include <stdexcept>
#include "include/dollar.h"
#include "include/franc.h"

void testMultiplication() {
    auto five = Dollar(5);
    TEST_ASSERT(Dollar(10) == five.times(2));
    TEST_ASSERT(Dollar(15) == five.times(3));
}

void testEquality() {
    TEST_ASSERT(Dollar(5) == Dollar(5));
    TEST_ASSERT(Dollar(5) != Dollar(6));
    TEST_ASSERT(Franc(5) == Franc(5));
    TEST_ASSERT(Franc(5) != Franc(6));
}

void testFrancMultiplication() {
    auto five = Franc(5);
    TEST_ASSERT(Franc(10) == five.times(2));
    TEST_ASSERT(Franc(15) == five.times(3));
}


TEST_LIST = {
    {"testMultiplication", testMultiplication},
    {"testEquality", testEquality},
    {"testFrancMultiplication", testFrancMultiplication},
    {nullptr, nullptr}
};
