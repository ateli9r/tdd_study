#include "../include/expression.h"
#include "../include/sum.h"

void* Expression::reduce(string to) {
    if (_expType == ExpressionType::SUM) {
        Sum* sum = (Sum*) this;
        return sum->reduce(to);
    }
}
