#include "../include/bank.h"
#include "../include/money.h"
#include "../include/expression.h"
#include "../include/sum.h"

Money* Bank::reduce(IExpression* source, string to) {
    return source->reduce(this, to);
}

Money* Bank::reduce(Money* source, string to) {
    return source->reduce(this, to);
}

string Bank::hashKey(string from, string to) {
    return from + "_" + to;
}

int Bank::rate(string from, string to) {
    if (from.compare(to) == 0) return 1; // USD == USD -> 1
    return this->rates[hashKey(from, to)];
}

void Bank::addRate(string from, string to, int rate) {
    auto data = unordered_map<string, int>::value_type(hashKey(from, to), rate);
    this->rates.insert(data);
}
