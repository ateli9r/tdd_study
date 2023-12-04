#ifndef __SUM_H__
#define __SUM_H__

#include "../include/expression.h"
#include "expression.h"
#include <string>
using std::string;

class Money;
class Bank;

class Sum : public IExpression {
private:
    IExpression* _augend;
    IExpression* _addend;
public:
    Sum(IExpression* augend, IExpression* addend) {
        this->_augend = augend;
        this->_addend = addend;
    }

    IExpression* reduce(Bank* bank, string to);
    IExpression* plus(IExpression addend);

    IExpression* augend();
    IExpression* addend();
};

#endif