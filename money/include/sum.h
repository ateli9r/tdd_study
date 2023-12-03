#ifndef __SUM_H__
#define __SUM_H__

#include "expression.h"
#include <string>
using std::string;

class Money;


class Sum : Expression {
private:
    Money* _augend;
    Money* _addend;
public:
    Sum(Money* augend, Money* addend);

    Money* reduce(string to);

    Money* augend();
    Money* addend();
};

#endif