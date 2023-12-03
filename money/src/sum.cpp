#include "../include/sum.h"
#include "../include/money.h"
#include "../include/expression.h"

Sum::Sum(Money* augend, Money* addend) {
    this->_augend = augend;
    this->_addend = addend;
    this->_expType = ExpressionType::SUM;
}

Money* Sum::reduce(string to) {
    int amount = this->_augend->amount() + this->_addend->amount();
    return new Money(amount, to);
}

Money* Sum::augend() {
    return this->_augend;
}

Money* Sum::addend() {
    return this->_addend;
}
