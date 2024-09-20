#ifndef EXP_H
#define EXP_H
#include <iostream>
using namespace std;

class Exp{
int base, exp;
public:
    int getValue();
    int getExp();
    int getBase();
    bool equals(Exp b);
    Exp();
    Exp(int base, int exp);
    Exp(int base);
};

#endif
