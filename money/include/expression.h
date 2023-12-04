#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>
using std::string;

class Money;
class Bank;

class IExpression {
public:
    virtual IExpression* reduce(Bank* bank, string to) { return nullptr; }
    virtual IExpression* plus(IExpression* addend) { return nullptr; }
    virtual IExpression* times(int multiplier) { return nullptr; }
};

#endif
