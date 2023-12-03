#ifndef __MONEY_H__
#define __MONEY_H__

#include <string>

class Money {
private:
    int _amount;
    std::string _currency;
public:
    Money(int amount, std::string currency);

    static Money dollar(int amount);
    static Money franc(int amount);

    Money times(int multiplier);
    
    bool equals(Money object);
    bool operator ==(Money object);
    bool operator !=(Money object);

    int amount();
    std::string currency();

};

#endif 