#include "../include/sum.h"
#include "../include/money.h"
#include "../include/bank.h"

IExpression* Sum::reduce(Bank* bank, string to) {
    int amount = ((Money*)this->_augend->reduce(bank, to))->amount()
        + ((Money*)this->_addend->reduce(bank, to))->amount();
    return new Money(amount, to);
}

IExpression* Sum::plus(IExpression addend) {
    return nullptr;
}

IExpression* Sum::augend() {
    return this->_augend;
}

IExpression* Sum::addend() {
    return this->_addend;
}
