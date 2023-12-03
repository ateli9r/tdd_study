#include "../include/money.h"

Money::Money(int amount, std::string currency) {
    this->_amount = amount;
    this->_currency = currency;
}

Money Money::dollar(int amount) {
    return Money(amount, "USD");
}

Money Money::franc(int amount) {
    return Money(amount, "CHF");
}

Money Money::times(int multiplier) {
    return Money(amount() * multiplier, currency());
}

bool Money::equals(Money object) {
    return amount() == object.amount()
        && currency().compare(object.currency()) == 0;
}

bool Money::operator ==(Money object) {
    return equals(object);
}

bool Money::operator !=(Money object) {
    return !equals(object);
}

int Money::amount() {
    return _amount;
}

std::string Money::currency() {
    return _currency;
}