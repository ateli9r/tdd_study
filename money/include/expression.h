#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>
using std::string;

enum ExpressionType {
    EXPRESSION,
    MONEY,
    SUM,
};

class Expression {
protected:
    ExpressionType _expType;
public:
    void* reduce(string to);
};

#endif