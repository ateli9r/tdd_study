#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>
using std::string;

class Money;
class Bank;

class IExpression {
public:
    virtual Money* reduce(Bank* bank, string to) { return nullptr; }
};

#endif
