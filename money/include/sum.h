#ifndef __SUM_H__
#define __SUM_H__

#include "../include/expression.h"
#include "expression.h"
#include <string>
using std::string;

class Money;
class Bank;
// class IExpression;

class Sum : public IExpression {
private:
    Money* _augend;
    Money* _addend;
public:
    Sum(Money* augend, Money* addend) {
        this->_augend = augend;
        this->_addend = addend;
    }

    Money* reduce(Bank* bank, string to);

    Money* augend();
    Money* addend();
};

#endif