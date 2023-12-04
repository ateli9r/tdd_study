#include "../include/money.h"
#include "../include/sum.h"
#include "../include/bank.h"

Money* Money::dollar(int amount) {
    return new Money(amount, "USD");
}

Money* Money::franc(int amount) {
    return new Money(amount, "CHF");
}

IExpression* Money::times(int multiplier) {
    return new Money(this->amount() * multiplier, this->currency());
}

bool Money::equals(IExpression* object) {
    auto money = (Money*) object;
    return this->amount() == money->amount()
        && this->currency().compare(money->currency()) == 0;
}

bool Money::notEquals(IExpression* object) {
    return !this->equals(object);
}

IExpression* Money::plus(IExpression* addend) {
    return new Sum(this, addend);
}

IExpression* Money::reduce(Bank* bank, string to) {
    int rate = bank->rate(this->currency(), to);
    return new Money(this->amount() / rate, to);
}

int Money::amount() {
    return _amount;
}

string Money::currency() {
    return _currency;
}
