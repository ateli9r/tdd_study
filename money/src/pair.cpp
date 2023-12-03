#include "../include/pair.h"

bool Pair::equals(Pair* pair) {
    return this->from.compare(pair->from) == 0
        && this->to.compare(pair->to) == 0;

}

int Pair::hashCode() {
    return 0;
}
