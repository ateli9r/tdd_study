#include "../include/sum.h"
#include "../include/money.h"
#include "../include/bank.h"

Money* Sum::reduce(Bank* bank, string to) {
    int amount = this->_augend->reduce(bank, to)->amount()
        + this->_addend->reduce(bank, to)->amount();
    return new Money(amount, to);
}

Money* Sum::augend() {
    return this->_augend;
}

Money* Sum::addend() {
    return this->_addend;
}
