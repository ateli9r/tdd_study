#ifndef __PAIR_H__
#define __PAIR_H__

#include <string>
using std::string;

class Pair {
public:
    string from;
    string to;

    Pair(string from, string to) {
        this->from = from;
        this->to = to;
    }

    bool equals(Pair* pair);

    int hashCode();
};

#endif