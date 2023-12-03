#ifndef __MONEY_H__
#define __MONEY_H__

// #include "expression.h"
// #include "bank.h"
#include <iostream>
#include <string>
using std::string;


class Bank;
class Expression;

class Money {
private:
    int _amount;
    std::string _currency;
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

    Expression* plus(Money* addend);
    Money* reduce(Bank* bank, string to);

    int amount();
    string currency();

};

#endif 