#ifndef __MONEY_H__
#define __MONEY_H__

class Money {
protected:
    int amount;
public:
    Money(int amount);

    Money times(int multiplier);
    
    bool equals(Money object);
    bool operator ==(Money object);
    bool operator !=(Money object);
};

#endif