#ifndef __BANK_H__
#define __BANK_H__

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;
using std::make_pair;

class Money;
class Expression;
class Pair;

class Bank {
private:
    unordered_map<string, int> rates;
public:
    Money* reduce(Expression* source, string to);
    Money* reduce(Money* source, string to);

    string hashKey(string from, string to);
    int rate(string from, string to);

    void addRate(string from, string to, int rate);
};

#endif