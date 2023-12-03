#include <stdexcept>
#include "../util/acutest.h"
#include "include/money.h"
#include "include/bank.h"
#include "include/expression.h"
#include "include/sum.h"

void testMultiplication() {
    auto five = Money::dollar(5); // $5
    TEST_ASSERT(Money::dollar(10)->equals(five->times(2))); // $5 x 2 = 10$
    TEST_ASSERT(Money::dollar(15)->equals(five->times(3))); // $5 x 3 = 15$
}

void testEquality() {
    TEST_ASSERT(Money::dollar(5)->equals(Money::dollar(5))); // $5 == $5
    TEST_ASSERT(Money::dollar(5)->notEquals(Money::dollar(6))); // $5 != $6
    TEST_ASSERT(Money::franc(5)->notEquals(Money::dollar(5))); // 5CHF != $5
}

void testCurrency() {
    TEST_ASSERT(Money::dollar(1)->currency().compare("USD") == 0); // 1$ = USD
    TEST_ASSERT(Money::franc(1)->currency().compare("CHF") == 0); // 1CHF = CHF
}

void testSimpleAddition() {
    Money* five = Money::dollar(5);
    Expression* sum = five->plus(five);
    Bank* bank = new Bank();
    Money* reduced = bank->reduce(sum, "USD");
    TEST_ASSERT(Money::dollar(10)->equals(reduced)); // $10 == $5 + $5
}

void testPlusReturnsSum() {
    Money* five = Money::dollar(5);
    Expression* result = five->plus(five);
    Sum* sum = (Sum*) result;
    TEST_ASSERT(five->equals(sum->augend())); // augend == $5
    TEST_ASSERT(five->equals(sum->addend())); // addend == $5
}

void testReduceSum() {
    Expression* sum = (Expression*) new Sum(Money::dollar(3), Money::dollar(4));
    Bank* bank = new Bank();
    Money* result = bank->reduce(sum, "USD");
    TEST_ASSERT(Money::dollar(7)->equals(result)); // $7 == $3 + $4
}

// void testReduceMoney() {
//     Bank* bank = new Bank();
//     Money* result = bank->reduce(Money::dollar(1), "USD");
//     TEST_ASSERT(Money::dollar(1)->equals(result));
// }

void testReduceMoneyDifferentCurrency() {
    Bank* bank = new Bank();
    bank->addRate("CHF", "USD", 2);
    Money* result = bank->reduce(Money::franc(2), "USD");
    TEST_ASSERT(Money::dollar(1)->equals(result));
}

void testIdentityRate() {
    TEST_ASSERT(1 == (new Bank())->rate("USD", "USD"));
}


TEST_LIST = {
    {"testMultiplication", testMultiplication},
    {"testEquality", testEquality},
    {"testCurrency", testCurrency},
    {"testSimpleAddition", testSimpleAddition},
    {"testPlusReturnsSum", testPlusReturnsSum},
    {"testReduceSum", testReduceSum},
    // {"testReduceMoney", testReduceMoney},
    {"testReduceMoneyDifferentCurrency", testReduceMoneyDifferentCurrency},
    {"testIdentityRate", testIdentityRate},
    {nullptr, nullptr}
};
