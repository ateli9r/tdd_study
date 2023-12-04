#ifndef __MONEY_H__
#define __MONEY_H__

#include "../include/expression.h"
#include <iostream>
#include <string>
using std::string;


class Bank;
class Sum;
class IExpression;

class Money : public IExpression {
private:
    int _amount;
    string _currency;
public:
    Money(int amount, string currency) {
        this->_amount = amount;
        this->_currency = currency;
    }

    static Money* dollar(int amount);
    static Money* franc(int amount);

    IExpression* times(int multiplier);
    
    bool equals(IExpression* object);
    bool notEquals(IExpression* object);

    IExpression* plus(IExpression* addend);
    IExpression* reduce(Bank* bank, string to);

    int amount();
    string currency();
};

#endif