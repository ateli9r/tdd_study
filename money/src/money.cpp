#include "../include/money.h"
#include "../include/sum.h"
#include "../include/bank.h"

Money* Money::dollar(int amount) {
    return new Money(amount, "USD");
}

Money* Money::franc(int amount) {
    return new Money(amount, "CHF");
}

Money* Money::times(int multiplier) {
    return new Money(this->amount() * multiplier, this->currency());
}

bool Money::equals(Money* object) {
    return this->amount() == object->amount()
        && this->currency().compare(object->currency()) == 0;
}

bool Money::notEquals(Money* object) {
    return !this->equals(object);
}

IExpression* Money::plus(Money* addend) {
    return new Sum(this, addend);
}

Money* Money::reduce(Bank* bank, string to) {
    int rate = bank->rate(this->currency(), to);
    return new Money(this->amount() / rate, to);
}

int Money::amount() {
    return _amount;
}

string Money::currency() {
    return _currency;
}
