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

    Money* times(int multiplier);
    
    bool equals(Money* object);
    bool notEquals(Money* object);

    IExpression* plus(Money* addend);
    Money* reduce(Bank* bank, string to);

    int amount();
    string currency();
};

#endif