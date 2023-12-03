#include "../include/dollar.h"

Money::Money(int amount) {
    this->amount = amount;
}

Money Money::times(int multiplier) {
    return Money(this->amount * multiplier);
}

bool Money::equals(Money object) {
    return amount == object.amount;
}

bool Money::operator ==(Money object) {
    return equals(object);
}

bool Money::operator !=(Money object) {
    return !equals(object);
}
